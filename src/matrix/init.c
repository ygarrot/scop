/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:15:19 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/25 13:23:59 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix	new_matrix(const int row, const int column)
{
	t_matrix	ret;

	if (!(ret.mat = (float**)ft_memalloc((row + 1) * sizeof(float*))))
		return (ret);
	ret.row = -1;
	ret.col = column;
	while (++ret.row < row)
		ret.mat[row] = (float*)ft_memalloc(column * sizeof(float));//FIXME check malloc
	return (ret);
}

/* t_mat4	matrix_identity(void) */
/* { */
/* 	return (t_mat4){ */
/* 		1, 0, 0, 0, */
/* 		0, 1, 0, 0, */
/* 		0, 0, 1, 0, */
/* 		0, 0, 0, 1, */
/* 	}; */
/* } */

t_matrix	matrix_identity(const int row, const int col)
{
	int	row;
	t_matrix	ret;

	ret = new_matrix(row, column);
	while (++row < ret.row)
		ret.mat[row][row] = 1;
}
