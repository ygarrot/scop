/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:44:13 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/09 12:16:49 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		usage(int argc, const char *argv[])
{
	if (argc < 2)
	{
		ft_printf("Please give me a filename\n");
		return (EXIT_FAILURE);
	}
	(void)argv;
	return (EXIT_SUCCESS);
}
int main(int argc, const char *argv[])
{
	/* t_vertex	v; */
	t_scop		scop;
	int			fd;
	char		*line;


	if (usage(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	while (get_next_line(fd, &line))
	{
		/* char **strings = ft_strsplit(line, ' '); */
		parser_iter(line, &scop);
	}
	/* parse_iter("v sds ", &scop); */
	return (0);
}
