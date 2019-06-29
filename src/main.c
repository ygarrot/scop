/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:44:13 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/29 16:06:58 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#define USAGE "Please give me a filename\n"
int		usage(int argc, const char *argv[])
{
	if (argc < 2)
	{
		ft_printf(USAGE);
		return (EXIT_FAILURE);
	}
	(void)argv;
	return (EXIT_SUCCESS);
}

int main(int argc, const char *argv[])
{
	t_scop		scop;
	int			fd;
	char		*line;

	ft_bzero(&scop, sizeof(scop));
	if (usage(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	while (get_next_line(fd, &line))
	{
		iter_obj(line, &scop);
	}

	scop.indices = list_to_array(ft_lstreverse(&scop.polygons));
	/* print_obj(&scop); */
	draw(&scop);
	/* t_matrix t = new_matrix(4, 4); */
	/* t_matrix t2 = new_matrix(4, 4); */
	/* t_matrix t3; */

	/* t.mat[0][0] = 3; */
	/* t.mat[0][1] = 2; */
	/* t.mat[0][2] = 4; */
	/* t.mat[0][3] = 3; */
	/* t3 = t; */
	/* t2.mat[0][0] = 1.2; */
	/* t2.mat[0][1] = 1; */
	/* t2.mat[0][2] = 1; */
	/* t2.mat[0][3] = 1; */
	
/* float mat3 */
	/* print_matrix(matrix_transpose(t2)); */

	return (0);
}
