/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:44:13 by ygarrot           #+#    #+#             */
/*   Updated: 2019/09/28 11:10:36 by ygarrot          ###   ########.fr       */
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
	/* for (int i = 0; scop.i */
	/* print_obj(&scop); */
	draw(&scop);
	return (0);
}
