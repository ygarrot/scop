/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlist_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:30:40 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/17 11:57:41 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_list *get_material_by_name(t_list *material, void *str)
{
	return (!ft_strcmp(((t_material*)material)->name, (char*)str) ? material : 0);
}


