/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler_to_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:32:24 by ygarrot           #+#    #+#             */
/*   Updated: 2019/12/14 15:53:40 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

//http://www.opengl-tutorial.org/assets/faq_quaternions/index.html#Q36

static t_euler_to_mat	generate_tmp(t_vector3 const euler)
{
	t_euler_to_mat tmp;

	tmp = (t_euler_to_mat){
		.a = cos(euler.x),
		.b = sin(euler.x),
		.c = cos(euler.y),
		.d = sin(euler.y),
		.e = cos(euler.z),
		.f = sin(euler.z),
	};
	tmp.ad = tmp.a * tmp.d;
	tmp.bd = tmp.b * tmp.d;
	return (tmp);
}

t_matrix4	euler_to_rotation_matrix(t_vector3 const euler)
{
	t_euler_to_mat	tmp;
	t_matrix4				matrix;

	tmp = generate_tmp(euler);
	matrix.tab[0][0] = tmp.c * tmp.e;
	matrix.tab[0][1] = -tmp.c * tmp.f;
	matrix.tab[0][2] = tmp.d;

	matrix.tab[1][0] = tmp.bd * tmp.e + tmp.a * tmp.f;
	matrix.tab[1][1] = -tmp.bd * tmp.f + tmp.a * tmp.e;
	matrix.tab[1][2] = -tmp.b * tmp.c;

	matrix.tab[2][0] = -tmp.ad * tmp.e + tmp.b * tmp.f;
	matrix.tab[2][1] = tmp.ad * tmp.f + tmp.b * tmp.e;
	matrix.tab[2][2] = tmp.a * tmp.c;
	return (matrix);
}
