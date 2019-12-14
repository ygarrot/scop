/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:15:19 by ygarrot           #+#    #+#             */
/*   Updated: 2019/12/14 16:11:08 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float *matrix4_to_array(const t_matrix4 matrix)
{
	float *array;
	int		row;
	int		col;

	if (!(array = ft_memalloc(sizeof(float) * 16)))
		return (NULL);
	row = -1;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
		{
			array[row * 4 + col] = matrix.tab[row][col];
		}
	}
	return (array);
}

t_matrix4	identity_matrix4(void)
{
	t_matrix4 matrix;

	ft_bzero(matrix.tab, sizeof(t_mat4));
	matrix.tab[0][0] = 1;
	matrix.tab[1][1] = 1;
	matrix.tab[2][2] = 1;
	matrix.tab[3][3] = 1;
	return matrix;
}

t_matrix4	vector3_to_matrix4(t_vector3 vec)
{
	t_matrix4 matrix;

	matrix.tab[0][0] = vec.x;
	matrix.tab[1][0] = vec.y;
	matrix.tab[2][0] = vec.z;
	return matrix;
}

/* t_vector3	matrix_to_vector3(t_matrix4 matrix) */
/* { */

/* 	return vector3; */
/* } */
