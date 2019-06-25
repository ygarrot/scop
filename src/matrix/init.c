/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:15:19 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/25 15:03:38 by ygarrot          ###   ########.fr       */
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
		ret.mat[ret.row] = (float*)ft_memalloc(column * sizeof(float));//FIXME check malloc
	return (ret);
}

t_matrix	matrix_identity(const int row, const int col)
{
	int	tmp;
	t_matrix	ret;

	tmp = 0;
	ret = new_matrix(row, col);
	while (++tmp < ret.row)
		ret.mat[tmp][tmp] = 1;
	return (ret);
}

/* float	*matrix_to_array(const t_matrix matrix) */
/* { */
	
/* } */
