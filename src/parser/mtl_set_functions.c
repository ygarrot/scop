/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_set_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:21:21 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/17 11:57:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_new_material(char **tab, void *struc)
{
	t_material	tmp;

	tmp = (t_material)
	{
		.name = tab[1] ? tab[1] : "default",
	};
	ft_lstadd((t_list**)struc, ft_lstnew(&tmp, sizeof(t_material)));
}

void	set_ambiant_color(char **tab, void *struc)
{
	string_to_color(tab, &as_material(struc)->Ka, 3);
}

void	set_diffuse_color(char **tab, void *struc)
{
	string_to_color(tab, &as_material(struc)->Kd, 3);
}

void	set_specular_color(char **tab, void *struc)
{
	string_to_color(tab, &as_material(struc)->Ks, 3);
}

void	set_specular_exponent(char **tab, void *struc)
{
	string_to_color(tab, &as_material(struc)->Ns, 3);
}
