/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:43:48 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/18 14:15:04 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
t_matrix	translate(t_matrix *matrix, t_vector3 const direction)
{
	t_matrix tmp = new_matrix(4, 1);
	tmp.mat[0][0] = direction.x;
	tmp.mat[1][0] = direction.y;
	tmp.mat[2][0] = direction.z;
	tmp.mat[3][0] = 1;
	return matrix_mul(*matrix, tmp);
}
