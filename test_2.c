/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:27:54 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/24 18:16:12 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>
typedef unsigned long size_t;

typedef struct	s_matrix
{
	size_t		row;
	size_t		col;
	float	**mat;
}				t_matrix;


t_matrix	new_matrix(size_t row, size_t column)
{
	t_matrix	ret;

	ret.mat = (float**)ft_memalloc((row + 1) * sizeof(float*));
	ret.row = row;
	ret.col = column;
	row = 0;
	while (row < ret.row)
		ret.mat[row++] = (float*)ft_memalloc(column * sizeof(float));
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

	vert_i = 0;
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
			matrix1.mat[vert_i][hor_i] * matrix2.mat[hor_i2][hor_i];
				++hor_i2;
			}
			printf("%f\n",ret.mat[vert_i][hor_i] ); 
			++hor_i;
		}
		++vert_i;
	}
	return ret;
}

int main()
{
	t_matrix t = new_matrix(4, 4);
	t_matrix t2;
	t_matrix t3;
	float **test;

	test = t.mat;
	t.mat[0][0] = 3;
	t.mat[0][1] = 2;
	t.mat[0][2] = 4;
	t.mat[0][3] = 3;
	t2 = t;
	t3 = t;
	
/* float mat3 */
	matrix_mul(t2, t3);
	return 1;
}
