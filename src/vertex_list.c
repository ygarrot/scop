/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:01:47 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/12 13:02:14 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_list	*get_vertex(t_list *vertex, void *struc)
{
	t_int_tab	*int_tab;
	size_t		i;
	int			vertex_index;

	i = 0;
	int_tab = struc;
	vertex_index = ((t_vertex*)vertex->content)->index;
	while (i < int_tab->size)
	{
		if (vertex_index == int_tab->tab[i])
			return (vertex);
		i++;
	}
	return (NULL);
}
