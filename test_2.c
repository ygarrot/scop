/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:27:54 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/23 17:36:18 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned long size_t;

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

	vert_i = 0;
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

int main()
{
	float mat1[3][3] = {
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
	};
float mat2[3][3] = {
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
	};

float mat3
	matrix_mul(mat1, mat2, 3, 3);

	return 1;
}
