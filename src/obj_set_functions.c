/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_set_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:27:39 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/12 13:04:54 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_vertex(char **split, void *struc)
{
	t_vertex	tmp;
	t_scop		*scop;
	t_list		*block;

	scop = struc;
	if (ft_tablen(split) < 4)
		ft_exit("vertex < 3", 1);
	tmp = (t_vertex)
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
	block = ft_lstnew(&tmp, sizeof(t_vertex));
	if (!block)
		ft_exit("BAD ALLOC", EXIT_FAILURE);
	ft_lstadd(&scop->vertices, block);
}

void	use_material(char **split, void *struc)
{
	t_scop		*scop;
	t_list		*tmp;
	
	scop = struc;
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
	t_face		polygon;
	t_list		*block;

	scop = struc;
	string_to_int_tab(split, &vertex_indices);
	polygon = (t_face)
	{
		.vertices = ft_lstfilter(scop->vertices,
								&vertex_indices,
								&get_vertex),
		.material = scop->current_material,
		.smoothing_group = scop->smoothing_group,
	};
	block = ft_lstnew(&polygon, sizeof(t_face));
	if (!block)
		ft_exit("BAD ALLOC", EXIT_FAILURE);
	ft_lstadd(&scop->polygons, block);
}
