/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:14:22 by ygarrot           #+#    #+#             */
/*   Updated: 2019/12/14 15:51:02 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix4	matrix_add(const t_matrix4 matrix, const t_matrix4 matrix2)
{
	t_matrix4	ret;
	int			row;
	int			col;

	row = -1;
	ft_bzero(&ret.tab, sizeof(t_mat4));
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
			ret.tab[row][col] = matrix.tab[row][col] + matrix2.tab[row][col];
	}
	return (ret);
}

t_matrix4	matrix_sub(const t_matrix4 matrix, const t_matrix4 matrix2)
{
	t_matrix4	ret;
	int			row;
	int			col;

	row = -1;
	ft_bzero(&ret.tab, sizeof(t_mat4));
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
			ret.tab[row][col] =
				matrix.tab[row][col] - matrix2.tab[row][col];
	}
	return (ret);
}

t_matrix4	matrix_mul(const t_matrix4 matrix1, const t_matrix4 matrix2)
{
	int		vert_i;
	int		hor_i;
	int		hor_i2;
	t_matrix4	ret;

	vert_i = -1;
	ft_bzero(&ret.tab, sizeof(t_mat4));
	while (++vert_i < 4)
	{
		hor_i = -1;
		while (++hor_i < 4)
		{
			hor_i2 = -1;
			while (++hor_i2 < 4)
			{
				ret.tab[vert_i][hor_i] +=
					matrix1.tab[vert_i][hor_i2] * matrix2.tab[hor_i2][hor_i];
			}
		}
	}
	return (ret);
}
