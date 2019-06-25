/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:27:54 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/25 13:46:50 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>
#include "includes/scop.h"
typedef unsigned long size_t;

int main()
{
	t_matrix t = new_matrix(4, 4);
	t_matrix t2 = new_matrix(4, 4);
	t_matrix t3;

	t.mat[0][0] = 3;
	t.mat[0][1] = 2;
	t.mat[0][2] = 4;
	t.mat[0][3] = 3;
	t3 = t;
	t2.mat[0][0] = 1.2;
	t2.mat[0][1] = 1;
	t2.mat[0][2] = 1;
	t2.mat[0][3] = 1;
	
/* float mat3 */
	print_matrix(matrix_transpose(t2));
	return 1;
}
