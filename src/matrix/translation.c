/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:43:48 by ygarrot           #+#    #+#             */
/*   Updated: 2019/12/14 16:39:54 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
t_matrix4	translate(t_matrix4 *matrix, t_vector3 const direction)
{
	t_matrix4 tmp = identity_matrix4();
	(void)matrix;
	/* return (tmp); */
	tmp.tab[0][3] = direction.x;
	tmp.tab[1][3] = direction.y;
	tmp.tab[2][3] = direction.z;
	/* tmp.mat[3][3] = 1; */
	return (tmp);
}
