/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:53:59 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/31 12:38:41 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
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


typedef struct	s_matrix
{
	int		row;
	int		col;
	float		**mat;
}				t_matrix;

/* typedef GLfloat[16] mat4; */

typedef struct	s_vector3
{
	float	x;
	float	y;
	float	z;
	/* double	w; */
}				t_vector3;


t_matrix	euler_to_rotation_matrix(t_vector3 const euler);

void		print_matrix(const t_matrix mat);
t_matrix	new_matrix(const int row, const int column);
t_matrix	matrix_add(const t_matrix matrix, const t_matrix matrix2);
t_matrix	matrix_sub(const t_matrix matrix, const t_matrix matrix2);
t_matrix	matrix_mul(const t_matrix matrix1, const t_matrix matrix2);
t_matrix	matrix_transpose(const t_matrix matrix);

t_matrix	identity_matrix(const int row, const int col);
t_matrix	new_matrix(const int row, const int column);
t_vector3	matrix_to_vector3(t_matrix matrix);
t_matrix	vector3_to_matrix(t_vector3 vec);
float	*matrix_to_array(const t_matrix matrix);

t_matrix	matrix4_x_rotate(float theta);
t_matrix	matrix4_y_rotate(float theta);
t_matrix	matrix4_z_rotate(float theta);
t_matrix	matrix_transpose(const t_matrix matrix);

t_matrix	translate(t_matrix *matrix, t_vector3 const direction);
void set_projection_matrix(t_matrix *mat, const float angle,
	   	const float near, const float far);

void perspective(const float fov, const float aspect,
	   	const float near, const float far, t_matrix *mret);
#endif
