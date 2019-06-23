/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:43:48 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/23 17:27:41 by ygarrot          ###   ########.fr       */
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

void mul_hor(
		float *matrix1,
		float *matrix2,
		size_t vert,
		size_t hor)
{

}

float	**matrix_mul(float **matrix1,
		float **matrix2,
		size_t vert,
		size_t hor)
{
	size_t	vert_i;
	size_t	hor_i;
	size_t	hor_i2;
	float	**ret;
	float	tmp;

	ret = (float*)ft_memalloc(sizeof(float) * vert * 2);
	while (vert_i < vert)
	{
		hor_i = 0;
		while (hor_i < hor)
		{
			tmp = 0;
			hor_i2 = 0;
			while (hor_i2 < hor)
			{
				tmp += matrix1[vert_i][hor_i2] * matrix2[hor_i2][hor_i];
				++hor_i2;
			}
			ret[vert_i][hor_i] = tmp;
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
