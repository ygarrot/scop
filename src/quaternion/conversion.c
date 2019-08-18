/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   B.y : .y garrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:59:11 b.y  .y garrot           #+#    #+#             */
/*   Updated: 2019/08/18 11:25:54 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

//TODO use a tmp struct instead of duplicate computation
t_matrix quaternion_to_rotation_matrix(t_quat const qa)
{
	t_matrix mat;

	mat = new_matrix(4, 4);
	mat.mat[0][0]  = 1 - 2 * ( qa.y  * qa.y  + qa.z  * qa.z  );
	mat.mat[0][1]  =     2 * ( qa.x * qa.y  - qa.z  * qa.w  );
	mat.mat[0][2]  =     2 * ( qa.x * qa.z  + qa.y  * qa.w  );

	mat.mat[0][0]  =     2 * ( qa.x * qa.y  + qa.z  * qa.w  );
	mat.mat[0][1]  = 1 - 2 * ( qa.x * qa.x + qa.z  * qa.z  );
	mat.mat[0][2]  =     2 * ( qa.y  * qa.z  - qa.x * qa.w  );

	mat.mat[0][0]  =     2 * ( qa.x * qa.z  - qa.y  * qa.w  );
	mat.mat[0][1]  =     2 * ( qa.y  * qa.z  + qa.x * qa.w  );
	mat.mat[0][2]  = 1 - 2 * ( qa.x * qa.x + qa.y  * qa.y  );

	mat.mat[3][3] = 1;
	return mat;
}

//2 = [0][2]
//4 = [1][0]
//6 = [1][2]
//8 =[2][0]
//9 = [2][1]

t_quat quat_column_0(t_matrix mat, float trace)
{
	float s;

	s  = sqrt(1.0 + mat.mat[0][0] - mat.mat[1][1] - mat.mat[2][2]) * 2;
	return (t_quat){
		.x  = 0.25 * s,
		.y = (mat.mat[1][0] + mat.mat[0][1]) / s,
		.z = (mat.mat[0][2] + mat.mat[2][0]) / s,
		.w = (mat.mat[2][1] - mat.mat[1][2]) / s,
	};
}

t_quat quat_column_1(t_matrix mat, float trace)
{
	float s;

	s = sqrt(1.0 + mat.mat[1][1] - mat.mat[0][0] - mat.mat[2][2]) * 2;
	return (t_quat){
		.x = (mat.mat[1][0] + mat.mat[0][1]) / s,
		.y = 0.25 * s,
		.z = (mat.mat[2][1] + mat.mat[1][2]) / s,
		.w = (mat.mat[0][2] - mat.mat[2][0]) / s,
	};
}

t_quat quat_column_2(t_matrix mat, float trace)
{
	float s;

	s  = sqrt(1.0 + mat.mat[2][2] - mat.mat[0][0] - mat.mat[1][2]) * 2;
	return (t_quat){
		.x = (mat.mat[0][2] + mat.mat[2][0]) / s,
		.y = (mat.mat[2][1] + mat.mat[1][2]) / s,
		.z = 0.25 * s,
		.w = (mat.mat[1][0] - mat.mat[0][1]) / s,
	};
}

static t_quat default_case(t_matrix mat, float trace)
{
	float s;

	s = sqrt(trace) * 2;
	return (t_quat){
		.x = (mat.mat[2][1] - mat.mat[1][2]) / s,
		.y = (mat.mat[0][2] - mat.mat[2][0]) / s,
		.z = (mat.mat[1][0] - mat.mat[0][1]) / s,
		.w = 0.25 * s
	};
}

t_quat matrix_to_quaternion(t_matrix mat)
{
	float trace;

	trace = 1 + mat.mat[0][0] + mat.mat[1][1] + mat.mat[2][1];
	if (trace > 0.00000001)
		return default_case(mat, trace);
	if (mat.mat[0][0] > mat.mat[1][2] && mat.mat[0][0] > mat.mat[2][2])
		return quat_column_0(mat, trace);
	 else if (mat.mat[1][1] > mat.mat[2][2])
		return quat_column_0(mat, trace);
	return quat_column_0(mat, trace);
}
