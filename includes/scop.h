/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:59:35 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/11 14:43:10 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <math.h>
# include "../libft/includes/libft.h"

typedef struct	s_func_dic
{
	char		*key;
	void		(*func)(char **, void *);
}				t_func_dic;

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vector;

typedef struct	s_vertex
{
	t_vector	v;
	char		*name;
	char		*usemtl;
	size_t		index;
}				t_vertex;

typedef enum	token
{
	VERTEX
	
}				t_token;

typedef struct	s_lexer_token
{
	char	*key;
	int		value;
}				t_lexer_token;

typedef struct s_face
{
	t_list	*vertices;
}				t_face;

typedef struct	s_scop
{
	t_list	*vertices;
	t_list	*polygon;
	t_list	*materials;
	char	*name;
	int		smoothing_group;
	int		vertices_nb;
}				t_scop;

typedef struct s_int_tab
{
	int		*tab;
	size_t	size;
}				t_int_tab;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

typedef struct	s_material
{
	char		*name;
	t_color		Ka;		//ambiant_color;
	t_color		Kd;		//diffuse_color;
	t_color		Ks;		//specular_color;
	t_color		Ns;		//specular exponent
	t_color		Ke;		//emissive_color;
	t_color		Tf;		//transmision filter
	double		Ni;		//optical density;
	double		d;		//transparency // disolve
	double		illum;	//color params;
}				t_material;

/* parser.c */
void	parse_obj(const t_func_dic *dic, char *string, t_scop *scop);
void	iter_obj(char *string, t_scop *scop);
void	create_vertex(char **value, void *struc);
t_list	*get_vertex(t_list *vertices, void *struc);


/* mtl_parser.c */

void	string_to_double(char **string,
						double *to_fill);
t_material	*as_material(void *ptr);
int		string_to_color(char **string,
			 			t_color *to_fill,
					   	int color_needed);
t_list		*file_to_materials(char *filename);
void	create_new_material(char **tab, void *struc);
void	set_ambiant_color(char **tab, void *struc);
void iter_mtl(char *string, t_list **materials);
void	parse_mtl(const t_func_dic *dic, char *string,
	   	t_list **materials);

/* mtl_set_functions_1.c */

void	set_illum(char **tab, void *struc);
void	set_transparency(char **tab, void *struc);
void	set_optical_density(char **tab, void *struc);
void	set_transmission_filter(char **tab, void *struc);
void	set_emissive_color(char **tab, void *struc);
void	set_specular_exponent(char **tab, void *struc);

/* mtl_set_functions.c */

void	set_specular_color(char **tab, void *struc);
void	set_diffuse_color(char **tab, void *struc);
void	set_ambiant_color(char **tab, void *struc);
void	create_new_material(char **tab, void *struc);

#endif
