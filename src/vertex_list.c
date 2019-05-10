/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:01:47 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/10 13:42:34 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_list	*get_vertex(t_list *vertices, void *struc)
{
	t_int_tab	*int_tab;
	size_t		i;

	i = 0;
	int_tab = struc;
	while (i < int_tab->size)
	{
		if (((t_vertex*)vertices->content)->index == i)
			return (vertices);
		i++;
	}
	return (NULL);
}
