/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_set_functions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:23:30 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/17 11:57:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"


void	set_emissive_color(char **tab, void *struc)
{
	string_to_color(tab, &as_material(struc)->Ke, 3);
}

void	set_transmission_filter(char **tab, void *struc)
{
	string_to_color(tab, &as_material(struc)->Tf, 3);
}

void	set_optical_density(char **tab, void *struc)
{
	string_to_double(tab, &as_material(struc)->Ni);
}

void	set_transparency(char **tab, void *struc)
{
	string_to_double(tab, &as_material(struc)->d);
}

void	set_illum(char **tab, void *struc)
{
	string_to_double(tab, &as_material(struc)->illum);
}
