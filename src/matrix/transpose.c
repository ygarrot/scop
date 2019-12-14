/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:39:18 by ygarrot           #+#    #+#             */
/*   Updated: 2019/12/14 16:03:31 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_matrix4	matrix4_transpose(const t_matrix4 matrix)
{
	int			row;
	int			col;
	t_matrix4	ret;

	row = -1;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
			ret.tab[col][row] = matrix.tab[row][col];
	}
	return (ret);
}
