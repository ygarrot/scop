/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:01:47 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/12 16:15:05 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_list	*get_vertex(t_list *vertex, void *struc)
{
	/* t_int_tab	*int_tab; */
	/* size_t		vertex_index; */
	/* size_t		i; */

	(void)vertex;
	(void)struc;
	return (NULL);
	/* i = 0; */
	/* int_tab = struc; */
	/* while (i < int_tab->size) */
	/* { */
	/* 	if (vertex_index == int_tab->tab[i]) */
	/* 		return (vertex); */
	/* 	i++; */
	/* } */
	/* return (NULL); */
}

void	list_to_vector_array(t_list *vertex, t_vector_array *to_fill)
{
	size_t	lst_size;
	size_t	i;
	/* t_vector_array *tmp; */

	lst_size = ft_lstsize(vertex);
	to_fill->size = lst_size;
	to_fill->vector = (t_vector*)malloc(lst_size * sizeof(t_vector));
	i = 0;
	while (i < lst_size)
	{
		to_fill->vector[i] = *((t_vector*)vertex->content);
		vertex = vertex->next;
		++i;
	}
}

void	string_to_index(char *string, int *tab)
{
	char	**tmp;
	int		i;

	tmp = ft_strsplit(string, '/');
	i = 0;
	while (tmp[i] && i < 3)
	{
		tab[i] = atof(tmp[i]);
		++i;
	}
}

t_vector	get_vector(t_vector_array const tab, size_t index)
{
	if (index < tab.size)
		return (tab.vector[index]);
	return ((t_vector){0 ,0 , 0});
}

void	array_to_vertices(char **string,
	   	t_vertex_array *to_fill,
	   	t_scop *scop)
{
	size_t	elements_nb;
	size_t	i;
	int		tab[3];

	elements_nb = ft_tablen(string);
	to_fill->size = elements_nb;
	to_fill->vertices = ft_memalloc(elements_nb * sizeof(t_vertex));
	i = 0;
	while (i < elements_nb)
	{
		string_to_index(string[i], tab);
		to_fill->vertices[i].position = get_vector(scop->vertices, tab[0]);
		to_fill->vertices[i].normal = scop->normals.vector[1];
		to_fill->vertices[i].textures = scop->textures.vector[2];
	}
}
