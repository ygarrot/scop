/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:42:08 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/12 12:46:58 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	print_vertex(t_vertex	*vertex)
{
	t_vector	vector;

	if (!vertex)
		return ;
	vector = vertex->v;
	printf("\t\tx: % 2.4lf y: % 2.4lf z:% 2.4lf w:% 2.4lf\n",
			vector.x,
			vector.y,
			vector.z,
			vector.w);
}

void	print_vertices(t_list *vertex)
{
	print_vertex((t_vertex*)vertex->content);
}

void	print_face(t_face *face)
{
	if (!face)
		return ;
	ft_lstiter(face->vertices, &print_vertices);
	print_mtl(face->material);
}

void	print_faces(t_list *face)
{
	print_face((t_face*)face->content);
}

void	print_obj(t_scop *scop)
{
	printf("Vertices:\n");
	ft_lstiter(scop->vertices, &print_vertices);
	printf("Polygons:\n");
	ft_lstiter(scop->polygons, &print_faces);
	printf("Materials:\n");
	ft_lstiter(scop->materials, &print_mtls);
}
