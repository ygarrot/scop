/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:43:48 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/25 13:15:31 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
void	translate(t_vector3 *vector, t_vector3 const direction)
{
	int	i;
	t_vector3 tmp;
	t_mat4 matrix= {
		1, 0, 0, direction.x,
		0, 1, 0, direction.y,
		0, 0, 1, direction.z,
		0, 0, 0, 1,
	};

	tmp = *vector;
	while (i < 4)
	{
		tmp.x += matrix.x[i] * vector->x;
		tmp.y += matrix.y[i] * vector->x;
		tmp.z += matrix.z[i] * vector->z;
		/* tmp.w += matrix.w[i] * 1; */
	}
	vector = &tmp;
}
