/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:27:54 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/25 13:26:31 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>
typedef unsigned long size_t;

typedef struct	s_matrix
{
	int		row;
	int		col;
	float		**mat;
}				t_matrix;

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

void	print_matrix(const t_matrix mat)
{
	int	row;
	int	col;

	row = -1;
	while (++row < mat.row)
	{
		col = -1;
		while (++col < mat.col)
			printf("[%.2f] ", mat.mat[row][col]);
		printf("\n");
	}
}

t_matrix matrix_sub(const t_matrix matrix, const t_matrix matrix2)
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


int main()
{
	t_matrix t = new_matrix(4, 4);
	t_matrix t2 = new_matrix(4, 4);
	t_matrix t3;

	t.mat[0][0] = 3;
	t.mat[0][1] = 2;
	t.mat[0][2] = 4;
	t.mat[0][3] = 3;
	t3 = t;
	t2.mat[0][0] = 1.2;
	t2.mat[0][1] = 1;
	t2.mat[0][2] = 1;
	t2.mat[0][3] = 1;
	
/* float mat3 */
	print_matrix(matrix_sub(t2, t3));
	return 1;
}
