/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_set_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:16:26 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/16 12:18:11 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	add_position(char **split, void *struc)
{
	create_vector(split, &((t_scop*)struc)->position_list);
}

void	add_normal(char **split, void *struc)
{
	create_vector(split, &((t_scop*)struc)->normal_list);
}

void	add_texture(char **split, void *struc)
{
	create_vector(split, &((t_scop*)struc)->texture_list);
}

void	set_smoothing_group(char **split, void *struc)
{
	((t_scop*)struc)->smoothing_group = atof(split[1]);
}

void	create_materials(char **split, void *struc)
{
	t_scop		*scop;
	scop = struc;

	scop->materials = file_to_materials(split[1]);
}
