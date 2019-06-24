/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:43:48 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/24 15:46:47 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat4	matrix_identity(void)
{
	return (t_mat4){
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1,
	};
}

float *matrix_add(float *matrix, float *matrix2, size_t size)
{
	float	*ret;
	size_t		i;

	i = 0;
	while (i < size)
	{
		matrix[i] += matrix2[i];
		++i;
	}
	return (ret);
}

float *matrix_sub(float *matrix,
		float *matrix2,
		size_t size)
{
	float	*ret;
	size_t		i;

	i = 0;
	while (i < size)
	{
		matrix[i] -= matrix2[i];
		++i;
	}
	return (ret);
}

t_matrix	new_matrix(size_t row, size_t column)
{
	t_matrix ret;

	ret.mat = ft_memalloc(row * sizeof(float**));
	while (row)
		ret.mat[row] = ft_memalloc(sizeof(float));
	return (ret);
}

t_matrix matrix_mul(t_matrix matrix1,
		t_matrix matrix2
		)
{
	size_t	vert_i;
	size_t	hor_i;
	size_t	hor_i2;
	t_matrix	ret;

	ret = new_matrix(matrix1.row, matrix1.row);
	while (vert_i < matrix1.row)
	{
		hor_i = 0;
		while (hor_i < matrix1.col)
		{
			hor_i2 = 0;
			while (hor_i2 < matrix1.col)
			{
				ret.mat[vert_i][hor_i] +=
			matrix1.mat[vert_i][hor_i2] * matrix2.mat[hor_i2][hor_i];
				++hor_i2;
			}
			++hor_i;
		}
		++vert_i;
	}
	return ret;
}

void	translate(t_vector3 *vector, t_vector3 const direction)
{
	int	i;
	t_vector3 tmp;
	t_mat4 matrix= {
		1, 0, 0, direction.x,
		0, 1, 0, direction.y,
		0, 0, 1, direction.z,
		0, 0, 0, 1,
	};

	tmp = *vector;
	while (i < 4)
	{
		tmp.x += matrix.x[i] * vector->x;
		tmp.y += matrix.y[i] * vector->x;
		tmp.z += matrix.z[i] * vector->z;
		/* tmp.w += matrix.w[i] * 1; */
	}
	vector = &tmp;
}
