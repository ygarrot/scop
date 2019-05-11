/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:39:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/11 15:19:16 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	string_to_double(char **string,
						double *to_fill)
{
	*to_fill = atof(string[1]);
}

t_material	*as_material(void *ptr)
{
	return ((t_material*)(*(t_list**)ptr)->content);
}

int		string_to_color(char **string,
			 			t_color *to_fill,
						int color_needed)
{
	t_color	tmp;
	int		argc;

	argc = ft_tablen(string);
	if (!string || argc < color_needed)
		return (0);
	tmp = (t_color)
	{
		.r = argc > 0 ? atof(string[1]) : 0.0,
		.g = argc > 1 ? atof(string[2]) : 0.0,
		.b = argc > 2 ? atof(string[3]) : 0.0,
	};
	ft_memcpy(to_fill, &tmp, sizeof(t_color));
	return (1);
}

void iter_mtl(char *string, t_list **materials)
{
	const t_func_dic parse_dic[] =
	{
		{"Ka", &set_ambiant_color},
		{"Kd", &set_diffuse_color},
		{"Ks", &set_specular_color},
		{"Ns", &set_specular_exponent},
		{"ke", &set_emissive_color},
		{"Tf", &set_transmission_filter},
		{"Ni", &set_optical_density},
		{"d", &set_transparency},
		{"illum", &set_illum},
		{"newmtl", &create_new_material},
		{0, 0},
	};

	parse_mtl(parse_dic, string, materials);
}

void	parse_mtl(const t_func_dic *dic,
					char *string,
					t_list **materials)
{
	if (!*string || !dic || !dic->key)
		return ;
	if (!strncmp(dic->key, string, ft_strlento(string, ' ')))
	{
		dic->func(ft_strsplit(string, ' '), materials);
	}
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
