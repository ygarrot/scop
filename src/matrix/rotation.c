/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:58:32 by ygarrot           #+#    #+#             */
/*   Updated: 2019/12/14 15:56:44 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix4	matrix4_x_rotate(float theta)
{
	t_matrix4 matrix; 

	ft_bzero(&matrix.tab, sizeof(t_mat4));
	matrix.tab[1][1] = cos(theta);
	matrix.tab[1][2] = -sin(theta);
	matrix.tab[2][1] = sin(theta);
	matrix.tab[1][2] = -cos(theta);
	return matrix;
}

t_matrix4	matrix4_y_rotate(float theta)
{
	t_matrix4 matrix; 

	ft_bzero(&matrix.tab, sizeof(t_mat4));
	matrix.tab[0][0] = cos(theta);
	matrix.tab[0][2] = sin(theta);
	matrix.tab[2][0] = -sin(theta);
	matrix.tab[2][2] = cos(theta);
	return matrix;
}

t_matrix4	matrix4_z_rotate(float theta)
{
	t_matrix4 matrix; 

	ft_bzero(&matrix.tab, sizeof(t_mat4));
	matrix.tab[0][0] = cos(theta);
	matrix.tab[0][1] = -sin(theta);
	matrix.tab[1][0] = sin(theta);
	matrix.tab[1][1] = -cos(theta);
	return matrix;
}
