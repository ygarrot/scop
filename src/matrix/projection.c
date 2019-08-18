/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:39:13 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/18 14:04:32 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void set_projection_matrix(t_matrix *mat, const float angle,
		const float near, const float far) 
{ 
	// set the basic projection matrix
	float scale = 1 / tan(angle * 0.5 * M_PI / 180);
	mat->mat[0][0] = scale; // scale the x coordinates of the projected point 
	mat->mat[1][1] = scale; // scale the y coordinates of the projected point 
	mat->mat[2][2] = -far / (far - near); // used to remap z to [0,1] 
	mat->mat[3][2] = -far * near / (far - near); // used to remap z [0,1] 
	mat->mat[2][3] = -1; // set w = -z 
	mat->mat[3][3] = 0; 
} 

void
perspective(const float fov, const float aspect,
	const float near, const float far,
   	t_matrix *mret)
{
	const float d2r = M_PI / 180.0;
	const float y_scale = 1.0 / tan(d2r * fov / 2);
	const float x_scale = y_scale / aspect;
	const float nearmfar = near - far;

	mret->mat[0][0] = x_scale;
	mret->mat[1][1] = y_scale;
	mret->mat[2][2] = (far + near) / nearmfar;
	mret->mat[2][3] = -1;
	mret->mat[3][2] = 2*far*near / nearmfar;
}
