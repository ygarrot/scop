/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:23:34 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/25 13:24:03 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

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



