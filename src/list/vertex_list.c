/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:01:47 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/16 14:52:17 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	count_array_size(t_list *list, void *new_size)
{
	*(size_t*)new_size += ((t_face*)list->content)->indices.size;
}

t_array	list_to_array(t_list *list)
{
	t_array ret;
	t_array	tmp;
	size_t	new_size;
	
	new_size = 0;
	ft_lstiter_s(list, &new_size, count_array_size); 
	tmp = (*(t_face*)list->content).indices;
	ret = (t_array)
	{
		.size = new_size,
		.content = ft_memalloc(tmp.content_size * new_size),
	};
	new_size = 0;
	while (list)
	{
		tmp = (*(t_face*)list->content).indices;
		/* int *tab = &((int*)ret.content)[new_size]; */
		/* ft_memcpy(&((int*)ret.content + new_size), */
		/* 		&tmp.content, */
		/* 		tmp.size * tmp.content_size); */
		/* if (!tab) */
		/* 	return ret; */
		for (size_t i = 0; i < tmp.size;i++)
		{
			((int*)ret.content)[new_size + i] = ((int*)tmp.content)[i];
			/* printf("%ld :", i); */
			printf("%d\n", ((int*)tmp.content)[i]);
			printf("%d\n", ((int*)ret.content)[new_size + i]);
		}
		new_size += tmp.size;
		list = list->next;
	}
	return (ret);
}

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

t_vector	*get_position(t_array *array)
{
	t_vector	*ret;
	size_t		i;

	i = 0;
	ret = (t_vector*)ft_memalloc(sizeof(t_vector) * array->size);
	while (i < array->size)
	{
		ret[i] = ((t_vertex*)array->content)[i].position;
		++i;
	}
	return ret;
}

t_vector	*get_all_polygon(t_list *polygons)
{
	t_vector *ret;
	size_t	i;
	size_t total;

	t_list *tmp = polygons;
	total = 0;
	while (tmp)
	{
		total += ((t_face*)tmp->content)->vertices.size;
		tmp = tmp->next;
	}
	ret = (t_vector*)ft_memalloc(sizeof(t_vector) * total);
	tmp = polygons;
	i = 0;
	while (tmp)
	{
		while (i < ((t_face*)tmp->content)->vertices.size)
		{
			ret[i] = ((t_vertex*)((t_face*)tmp->content)->vertices.content)[i].position;
			++i;
			total--;
			printf("%ld\n", total);
		}
		i = 0;
		tmp = tmp->next;
	}
	return ret;
}

void	list_to_vector_array(t_list *vertex, t_array *to_fill)
{
	size_t	lst_size;
	size_t	i;

	lst_size = ft_lstsize(vertex);
	to_fill->size = lst_size;
	to_fill->content = (t_vector*)malloc(lst_size * sizeof(t_vector));
	to_fill->content_size = sizeof(t_vector);
	i = 0;
	while (i < lst_size)
	{
		((t_vector*)to_fill->content)[i] = *((t_vector*)vertex->content);
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

t_vector	get_vector(t_array const tab, size_t index)
{
	if (index < tab.size)
		return (((t_vector*)tab.content)[index]);
	return ((t_vector){0 ,0 , 0});
}

void	array_to_vertices(char **string,
		t_array *to_fill,
		t_scop *scop)
{
	size_t	elements_nb;
	size_t	i;
	int		tab[3];

	elements_nb = ft_tablen(string) - 1;
	to_fill->size = elements_nb;
	to_fill->content = ft_memalloc(elements_nb * sizeof(t_vertex));
	to_fill->content_size = sizeof(t_vertex);
	i = 0;
	if (!scop->positions.size)
	{
		list_to_vector_array(scop->position_list, &scop->positions);
		list_to_vector_array(scop->normal_list, &scop->normals);
		list_to_vector_array(scop->texture_list, &scop->textures);
	}
	while (i < elements_nb)
	{
		string_to_index(string[i], tab);
		((t_vertex*)to_fill->content)[i].position = get_vector(scop->positions, tab[0]);
		((t_vertex*)to_fill->content)[i].normal = get_vector(scop->normals, tab[1]);
		((t_vertex*)to_fill->content)[i].textures = get_vector(scop->textures, tab[2]);
		++i;
	}
}
