/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:42:08 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/31 12:01:03 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	print_vector(t_vector3 const vector)
{
	printf("\t\tx: % 2.4lf y: % 2.4lf z:% 2.4lf w:% 2.4lf\n",
			vector.x,
			vector.y,
			vector.z,
			0.0);
}

void	print_vertex(t_vertex	*vertex)
{
	if (!vertex)
		return ;
	printf("\t position: ");
	print_vector(vertex->position);
	printf("\t normal: ");
	print_vector(vertex->normal);
	printf("\t texture: ");
	print_vector(vertex->textures);
}

void	print_vertices(t_list *vertex)
{
	print_vertex((t_vertex*)vertex->content);
}

void	print_vector_array(t_array const array)
{
	size_t		i;

	i = 0;
	while (i < array.size)
	{
		print_vector(((t_vector3*)array.content)[i]);
		++i;
	}
}

void	print_vertex_array(t_array const array)
{
	size_t		i;

	i = 0;
	while (i < array.size)
	{
		print_vertex(&((t_vertex*)array.content)[i]);
		++i;
	}
}

void	print_face(t_face *face)
{
	if (!face)
		return ;
	print_vertex_array(face->vertices);
	print_mtl(face->material);
}

void	print_faces(t_list *face)
{
	print_face((t_face*)face->content);
}

void	print_obj(t_scop *scop)
{
	printf("Vertices:\n");
	print_vector_array(scop->positions);
	print_vector_array(scop->normals);
	print_vector_array(scop->textures);
	printf("Polygons:\n");
	ft_lstiter(scop->polygons, &print_faces);
	printf("Materials:\n");
	ft_lstiter(scop->materials, &print_mtls);
}
