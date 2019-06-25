/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:14:22 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/25 13:22:54 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix	matrix_add(const t_matrix matrix, const t_matrix matrix2)
{
	t_matrix	ret;
	int			row;
	int			col;

	ret = new_matrix(matrix.row, matrix.col);
	row = -1;
	while (++row < ret.row)
	{
		col = -1;
		while (++col < ret.col)
			ret.mat[row][col] = matrix.mat[row][col] + matrix2.mat[row][col];
	}
	return (ret);
}

t_matrix	matrix_sub(const t_matrix matrix, const t_matrix matrix2)
{
	t_matrix	ret;
	int			row;
	int			col;

	ret = new_matrix(matrix.row, matrix.col);
	row = -1;
	while (++row < ret.row)
	{
		col = -1;
		while (++col < ret.col)
			ret.mat[row][col] = matrix.mat[row][col] - matrix2.mat[row][col];
	}
	return (ret);
}

t_matrix	matrix_mul(const t_matrix matrix1, const t_matrix matrix2)
{
	int		vert_i;
	int		hor_i;
	int		hor_i2;
	t_matrix	ret;

	vert_i = -1;
	ret = new_matrix(matrix1.row, matrix1.row);
	while (++vert_i < matrix1.row)
	{
		hor_i = -1;
		while (++hor_i < matrix1.col)
		{
			hor_i2 = -1;
			while (++hor_i2 < matrix1.col)
			{
				ret.mat[vert_i][hor_i] +=
			matrix1.mat[vert_i][hor_i] * matrix2.mat[hor_i2][hor_i];
			}
		}
	}
	return ret;
}
