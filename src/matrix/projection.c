/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:39:13 by ygarrot           #+#    #+#             */
/*   Updated: 2019/12/14 15:35:53 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void set_projection_matrix(
		t_matrix4 *mat,
		const float angle,
		const float near,
		const float far
		) 
{ 
	// set the basic projection matrix
	float scale = 1 / tan(angle * 0.5 * M_PI / 180);
	mat->tab[0][0] = scale; // scale the x coordinates of the projected point 
	mat->tab[1][1] = scale; // scale the y coordinates of the projected point 
	mat->tab[2][2] = -far / (far - near); // used to remap z to [0,1] 
	mat->tab[3][2] = -far * near / (far - near); // used to remap z [0,1] 
	mat->tab[2][3] = -1; // set w = -z 
	mat->tab[3][3] = 0; 
} 

void perspective(
		t_matrix4 *matrix,
		const float fov,
		const float aspect,
		const float near,
		const float far
		)
{
	const float d2r = M_PI / 180.0;
	const float y_scale = 1.0 / tan(d2r * fov / 2);
	const float x_scale = y_scale / aspect;
	const float nearmfar = near - far;

	matrix->tab[0][0] = x_scale;
	matrix->tab[1][1] = y_scale;
	matrix->tab[2][2] = (far + near) / nearmfar;
	matrix->tab[2][3] = -1;
	matrix->tab[3][2] = 2 * far * near / nearmfar;
}
