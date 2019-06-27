/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:58:32 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/27 13:20:51 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix	matrix4_x_rotate(float theta)
{
	t_matrix matrix;

	matrix = identity_matrix(4, 4);
	matrix.mat[1][1] = cos(theta);
	matrix.mat[1][2] = -sin(theta);
	matrix.mat[2][1] = sin(theta);
	matrix.mat[1][2] = -cos(theta);
	return (matrix);
}

t_matrix	matrix4_y_rotate(float theta)
{
	t_matrix matrix;

	matrix = identity_matrix(4, 4);
	matrix.mat[0][0] = cos(theta);
	matrix.mat[0][2] = sin(theta);
	matrix.mat[2][0] = -sin(theta);
	matrix.mat[2][2] = cos(theta);
	return (matrix);
}

t_matrix	matrix4_z_rotate(float theta)
{
	t_matrix matrix;

	matrix = identity_matrix(4, 4);
	matrix.mat[0][0] = cos(theta);
	matrix.mat[0][1] = -sin(theta);
	matrix.mat[1][0] = sin(theta);
	matrix.mat[1][1] = cos(theta);
	return (matrix);
}
