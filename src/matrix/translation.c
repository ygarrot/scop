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
	t_matrix tmp = identity_matrix(4, 4);

	(void)matrix;
	tmp.mat[0][3] = direction.x;
	tmp.mat[1][3] = direction.y;
	tmp.mat[2][3] = direction.z;
	/* tmp.mat[3][3] = 1; */
	return (tmp);
	/* return matrix_mul(*matrix, tmp); */
}
