/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:39:18 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/25 13:55:59 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix	matrix_transpose(const t_matrix matrix)
{
	int			row;
	int			col;
	t_matrix	ret;

	ret = new_matrix(matrix.col, matrix.row);
	row = -1;
	while (++row < matrix.row)
	{
		col = -1;
		while (++col < matrix.col)
			ret.mat[col][row] = matrix.mat[row][col];
	}
	return (ret);
}
