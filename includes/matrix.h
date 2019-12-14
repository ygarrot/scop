/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:53:59 by ygarrot           #+#    #+#             */
/*   Updated: 2019/12/14 16:07:30 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
# include <stdio.h>
#include "../libft/includes/libft.h"

typedef struct s_euler_to_mat
{
	float		a;
	float		b;
	float		c;
	float		d;
	float		e;
	float		f;

	float		ad;
	float		bd;
}				t_euler_to_mat;

/* typedef float t_matrix3[3][3]; */
typedef float t_mat4[4][4];

typedef struct s_matrix4
{
	t_mat4		tab;
} 				t_matrix4;

typedef struct	s_vector3
{
	float	x;
	float	y;
	float	z;
	/* double	w; */
}				t_vector3;

t_matrix4	euler_to_rotation_matrix(t_vector3 const euler);

void		print_matrix4(const t_matrix4 mat);
t_matrix4	matrix_add(const t_matrix4 matrix, const t_matrix4 matrix2);
t_matrix4	matrix_sub(const t_matrix4 matrix, const t_matrix4 matrix2);
t_matrix4	matrix_mul(const t_matrix4 matrix, const t_matrix4 matrix2);

t_matrix4	matrix4_transpose(const t_matrix4 matrix);

t_matrix4	identity_matrix4(void);

t_matrix4	vector3_to_matrix4(t_vector3 vec);

t_matrix4	matrix4_x_rotate(float theta);
t_matrix4	matrix4_y_rotate(float theta);
t_matrix4	matrix4_z_rotate(float theta);

t_matrix4	translate(t_matrix4 *matrix, t_vector3 const direction);
t_matrix4	matrix4_transpose(const t_matrix4 matrix);
float		*matrix4_to_array(const t_matrix4 matrix);

void set_projection_matrix(
		t_matrix4 *mat,
		const float angle,
		const float near,
		const float far
		);

void perspective(
		t_matrix4 *mret,
		const float fov,
		const float aspect,
		const float near,
		const float far
		);

#endif
