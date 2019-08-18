/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:15:19 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/18 13:11:25 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	new_matrix(const int row, const int column)
{
	t_matrix	ret;

	if (!(ret.mat = (float**)ft_memalloc((row + 1) * sizeof(float*))))
		return (ret);
	ret.row = -1;
	ret.col = column;
	while (++ret.row < row)
		ret.mat[ret.row] = (float*)ft_memalloc(column * sizeof(float));//FIXME check malloc
	return (ret);
}

t_matrix	identity_matrix(const int row, const int col)
{
	int	tmp;
	t_matrix	ret;

	tmp = -1;
	ret = new_matrix(row, col);
	while (++tmp < row)
		ret.mat[tmp][tmp] = 1;
	return (ret);
}

t_vector3	matrix_to_vector3(t_matrix matrix)
{
	t_vector3 tmp;

	ft_memcpy(&tmp, matrix.mat, sizeof(tmp));
	return (tmp);
}

t_matrix	vector3_to_matrix(t_vector3 vec)
{
	t_matrix tmp;

	tmp = new_matrix(3, 1);
	tmp.mat[0][0] = vec.x;
	tmp.mat[1][0] = vec.y;
	tmp.mat[2][0] = vec.z;
	return (tmp);
}

float	*matrix_to_array(const t_matrix matrix)
{
	float *array;
	int		row;
	int		col;

	if (!(array = ft_memalloc(sizeof(float) * matrix.col * matrix.row)))
		return (NULL);
	row = -1;
	while (++row < matrix.row)
	{
		col = -1;
		while (++col < matrix.col)
		{
			array[row * matrix.col + col] = matrix.mat[row][col];
		}
	}
	return (array);
}
