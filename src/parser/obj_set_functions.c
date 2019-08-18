/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_set_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:27:39 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/18 10:51:28 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_vector(char **split, t_list **stack)
{
	t_vector3	tmp;
	t_list		*block;

	if (ft_tablen(split) < 4)
		ft_exit("vertex < 3", 1);
	tmp = (t_vector3)
	{
			.x = atof(split[1]),
			.y = atof(split[2]),
			.z = atof(split[3]),
			/* .w = (ft_tablen(split) > 4) ? atof(split[1]) : 1.0 */
	};
	block = ft_lstnew(&tmp, sizeof(t_vector3));
	if (!block)
		ft_exit("BAD ALLOC", EXIT_FAILURE);
	ft_lstpushback(stack, block);
}

void	use_material(char **split, void *struc)
{
	t_scop		*scop;
	t_list		*tmp;
	
	scop = struc;
	tmp = ft_lstfilter(scop->materials, split[1], &get_material_by_name);
	if (tmp)
		scop->current_material = (t_material*)tmp->content;
}

void	create_polygon(char **split, void *struc)
{
	t_array	vertex_indices;
	t_scop		*scop;
	t_face		polygon;
	t_list		*block;

	scop = struc;
	string_to_int_tab(split, &vertex_indices);
	polygon = (t_face)
	{
		.material = scop->current_material,
		.smoothing_group = scop->smoothing_group,
		.indices = vertex_indices,
	};
	array_to_vertices(split, &polygon.vertices, scop);
	block = ft_lstnew(&polygon, sizeof(t_face));
	scop->pos_nb += polygon.indices.size;
	if (!block)
		ft_exit("BAD ALLOC", EXIT_FAILURE);
	ft_lstadd(&scop->polygons, block);
}
