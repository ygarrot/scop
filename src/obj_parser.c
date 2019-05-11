/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:39:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/11 16:22:15 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_vertex(char **split, void *struc)
{
	t_vertex	*tmp;
	t_scop		*scop;
	t_list		*block;

	scop = struc;
	if (ft_tablen(split) < 4)
		ft_exit("vertex < 3", 1);
	tmp = &(t_vertex)
	{
		.v =
	   	{
			.x = atof(split[1]),
			.y = atof(split[1]),
			.z = atof(split[1]),
			.w = (ft_tablen(split) > 4) ? atof(split[1]) : 1.0
		},
		.index = scop->vertices_nb++
	};
	block = ft_lstnew(&tmp, sizeof(*tmp));
	if (!block)
		ft_exit("BAD ALLOC", EXIT_FAILURE);
	ft_lstadd(&scop->vertices, block);
}

void	string_to_int_tab(char **split, t_int_tab *int_tab)
{
	size_t		i;

	i = 1;
	if (!split)
		return ;
	*int_tab = (t_int_tab)
	{
		.tab = (int*)ft_memalloc((ft_tablen(split) - 1) * sizeof(int)),
		.size = ft_tablen(split) - 1,
	};
	while (split[i])
	{
		int_tab->tab[i - 1] = ft_atoi(split[i]);
		++i;
	}
}

t_list *get_material_by_name(t_list *material, void *str)
{
	return (!ft_strcmp(((t_material*)material)->name, (char*)str) ? material : 0);
}

void	use_material(char **split, void *struc)
{
	t_scop		*scop;
	t_list		*tmp;
	
	scop = struc;
	(void)split;
	(void)tmp;
	tmp = ft_lstfilter(scop->vertices, split[1], &get_material_by_name);
	if (tmp)
		scop->current_material = (t_material*)tmp->content;
}

void	set_smoothing_group(char **split, void *struc)
{
	((t_scop*)struc)->smoothing_group = atof(split[1]);
}

void	create_materials(char **split, void *struc)
{
	t_scop		*scop;
	scop = struc;

	scop->materials = file_to_materials(split[1]);
}

void	create_polygon(char **split, void *struc)
{
	t_int_tab	vertex_indices;
	t_scop		*scop;
	t_face		*polygon;
	t_list		*block;

	scop = struc;
	string_to_int_tab(split, &vertex_indices);
	polygon = &(t_face)
	{
		.vertices = ft_lstfilter(scop->vertices,
								&vertex_indices,
								&get_vertex),
		.material = scop->current_material,
		.smoothing_group = scop->smoothing_group,
	};
	block = ft_lstnew(&polygon, sizeof(*polygon));
	if (!block)
		ft_exit("BAD ALLOC", EXIT_FAILURE);
	ft_lstadd(&scop->polygon, block);
}

void iter_obj(char *string, t_scop *scop)
{
	const t_func_dic parse_dic[] =
	{
		{"v", &create_vertex},
		{"f", &create_polygon},
		{"s", &set_smoothing_group},
		{"usemtl", &use_material},
		{"mtllib", &create_materials},
		{0, 0},
	};

	parse_obj(parse_dic, string, scop);
}

void	parse_obj(const t_func_dic *dic, char *string, t_scop *scop)
{
	if (!dic || !dic->key)
		return ;
	if (!strncmp(dic->key, string, ft_strlento(string, ' ')))
		dic->func(ft_strsplit(string, ' '), scop);
	parse_obj(dic + 1, string, scop);
}
