/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:39:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/10 14:08:09 by ygarrot          ###   ########.fr       */
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
	};
	block = ft_lstnew(&polygon, sizeof(*polygon));
	if (!block)
		ft_exit("BAD ALLOC", EXIT_FAILURE);
	ft_lstadd(&scop->polygon, block);
}

void parser_iter(char *string, t_scop *scop)
{
	const t_func_dic parse_dic[] =
	{
		{"v", &create_vertex},
		{"f", &create_polygon},
		{0, 0},
	};

	parse(parse_dic, string, scop);
}

void	parse(const t_func_dic *dic, char *string, t_scop *scop)
{
	if (!dic || !dic->key)
		return ;
	if (!strncmp(dic->key, string,ft_strlento(string, ' ')))
		dic->func(ft_strsplit(string, ' '), scop);
	parse(dic + 1, string, scop);
}
