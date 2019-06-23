/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:39:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/17 11:57:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	string_to_int_tab(char **split, t_array *int_tab)
{
	size_t		i;

	i = 1;
	if (!split)
		return ;
	*int_tab = (t_array)
	{
		.content = (int*)ft_memalloc((ft_tablen(split) - 1) * sizeof(int)),
		.size = ft_tablen(split) - 1,
		.content_size = sizeof(int),
	};
	while (split[i])
	{
		((int*)int_tab->content)[i - 1] = ft_atoi(split[i]);
		++i;
	}
}

void iter_obj(char *string, t_scop *scop)
{
	const t_func_dic parse_dic[] =
	{
		{"v", &add_position},
		{"vt", &add_texture},
		{"vn", &add_normal},
		{"f", &create_polygon},
		{"s", &set_smoothing_group},
		{"usemtl", &use_material},
		{"mtllib", &create_materials},
		{0, 0},
	};

	parse_obj(parse_dic, string, scop);
}

void	parse_obj(const t_func_dic *dic, char *string, t_scop *scop)
{
	if (!dic || !dic->key)
		return ;
	if (!strncmp(dic->key, string, ft_strlento(string, ' ')))
		dic->func(ft_strsplit(string, ' '), scop);
	parse_obj(dic + 1, string, scop);
}
