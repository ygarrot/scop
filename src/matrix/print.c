/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:23:34 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/30 15:00:25 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

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
