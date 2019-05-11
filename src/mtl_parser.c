/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:39:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/11 12:54:09 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		string_to_color(char **string,
			 			t_color *to_fill,
					   	int color_needed)
{
	int		argc;

	argc = ft_tablen(string);
	if (!string || argc < color_needed)
		return (0);
	to_fill = &(t_color)
	{
		.r = argc > 0 ? atof(string[0]) : 0.0,
		.g = argc > 1 ? atof(string[0]) : 0.0,
		.b = argc > 2 ? atof(string[0]) : 0.0,
	};
	return (1);
}

void	create_new_material(char **tab, void *struc)
{
	t_material	tmp;

	ft_printf("filet_o\n");
	tmp = (t_material)
	{
		.name = tab[1],
	};
	ft_lstadd((t_list**)struc, ft_lstnew(&tmp, sizeof(t_material)));
}

void	set_ambiant_color(char **tab, void *struc)
{
	string_to_color(tab,
		   	&((t_material*)(*(t_list**)struc)->content)->Ka, 3);
}

void iter_mtl(char *string, t_list **materials)
{
	const t_func_dic parse_dic[] =
	{
		{"Ka", &set_ambiant_color},
		{"newmtl", &create_new_material},
		{0, 0},
	};

	parse_mtl(parse_dic, string, materials);
}

void	parse_mtl(const t_func_dic *dic,
					char *string,
					t_list **materials)
{
	if (!dic || !dic->key)
		return ;
	if (!strncmp(dic->key, string, ft_strlento(string, ' ')))
		dic->func(ft_strsplit(string, ' '), materials);
	parse_mtl(dic + 1, string, materials);
}

t_list		*file_to_materials(char *filename)
{
	t_list		*materials;
	t_material	tmp;
	int			fd;
	char		*line;

	filename = "resources/42.mtl";
	tmp = (t_material)
	{
		.name = "",
	};
	materials = ft_lstnew(&tmp, sizeof(t_material));
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		iter_mtl(line, &materials);
	}
	return (materials);
}
