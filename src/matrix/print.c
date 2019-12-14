/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:23:34 by ygarrot           #+#    #+#             */
/*   Updated: 2019/12/14 15:43:15 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	print_matrix4(const t_matrix4 mat)
{
	int	row;
	int	col;

	row = -1;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
			printf("[%.2f] ", mat.tab[row][col]);
		printf("\n");
	}
}
