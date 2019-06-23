/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 15:00:14 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/17 11:57:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	print_color(t_color color)
{
	printf("\t\tred: %lf green: %lf blue: %lf\n",
			color.r,
			color.g,
			color.b
		  );
}

void	print_mtl(t_material *material)
{
	if (!material)
		return ;
	printf("[ %s ]\n", material->name);
	printf("ambiant_color:\n");
	print_color(material->Ka);
	printf("diffuse_color:\n");
	print_color(material->Kd);
	printf("specular_color:\n");
	print_color(material->Ks);
	printf("specular_exponent:\n");
	print_color(material->Ns);
	printf("emissive_color:\n");
	print_color(material->Ke);
	printf("transmission_filter:\n");
	print_color(material->Tf);
	printf("optical_density: %lf\n"
			"transparency: %lf\n"
			"illum: %lf\n",
			material->Ni,
			material->d,
			material->illum);
}

void	print_mtls(t_list *material)
{
	print_mtl((t_material*)material->content);
}
