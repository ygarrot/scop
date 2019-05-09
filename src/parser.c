/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:39:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/09 13:34:14 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	create_vertex(char *value, void *struc)
{
	t_vertex	*tmp;
	t_scop		*scop;
	char		**split;

	scop = struc;
	split = ft_strsplit(value, ' ');
	if (ft_tablen(split) < 4)
		ft_exit("vertex < 3", 1);
	tmp = &(t_vertex){
		.x = atof(split[1]),
		.y = atof(split[1]),
		.z = atof(split[1]),
		.w = (ft_tablen(split) > 4) ? atof(split[1]) : 1.0
	};
	t_list	*block = ft_lstnew(&tmp, sizeof(*tmp));
	ft_lstadd(&scop->vertices, block);
}


void parser_iter(char *string, t_scop *scop)
{
	const t_func_dic parse_dic[2] =
	{
		{"v", &create_vertex},
		{0, 0},
	};

	parse(parse_dic, string, scop);
}

void	parse(const t_func_dic *dic, char *string, t_scop *scop)
{
	if (!dic || !dic->key)
		return ;
	if (!strncmp(dic->key, string,ft_strlento(string, ' ')))
		dic->func(string, scop);
	parse(dic + 1, string, scop);
}
