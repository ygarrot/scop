/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:59:35 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/12 11:59:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <math.h>
# include "../libft/includes/libft.h"

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
	t_list		*vertices;
	t_material	*material;
	int			smoothing_group;
}				t_face;

typedef struct	s_scop
{
	t_list		*vertices;
	t_list		*polygons;
	t_list		*materials;
	t_material	*current_material;
	char		*name;
	int			smoothing_group;
	int			vertices_nb;
}				t_scop;

typedef struct s_int_tab
{
	int		*tab;
	size_t	size;
}				t_int_tab;


/* vertex_list.c */

t_list		*get_vertex(t_list *vertices, void *struc);


/* tlist_functions.c */

t_list *get_material_by_name(t_list *material, void *str);


/* obj_parser.c */

void		parse_obj(const t_func_dic *dic,
						char *string, t_scop *scop);
void		iter_obj(char *string, t_scop *scop);
void		string_to_int_tab(char **split, t_int_tab *int_tab);


/* obj_set_functions.c */

void		use_material(char **split, void *struc);
void		create_polygon(char **split, void *struc);
void		set_smoothing_group(char **split, void *struc);
void		create_vertex(char **value, void *struc);
void		create_materials(char **split, void *struc);


/* obj_print.c */

void	print_obj(t_scop *scop);
void	print_faces(t_list *face);
void	print_face(t_face *face);
void	print_vertices(t_list *vertex);
void	print_vertex(t_vertex	*vertex);


/* mtl_parser.c */

void		string_to_double(char **string,
							double *to_fill);
t_material	*as_material(void *ptr);
int			string_to_color(char **string,
							t_color *to_fill,
							int color_needed);
t_list		*file_to_materials(char *filename);
void		iter_mtl(char *string, t_list **materials);
void		parse_mtl(const t_func_dic *dic, char *string,
					t_list **materials);


/* mtl_set_functions_1.c */

void		set_illum(char **tab, void *struc);
void		set_transparency(char **tab, void *struc);
void		set_optical_density(char **tab, void *struc);
void		set_transmission_filter(char **tab, void *struc);
void		set_emissive_color(char **tab, void *struc);
void		set_specular_exponent(char **tab, void *struc);


/* mtl_set_functions.c */

void		set_specular_color(char **tab, void *struc);
void		set_diffuse_color(char **tab, void *struc);
void		set_ambiant_color(char **tab, void *struc);
void		create_new_material(char **tab, void *struc);


/* mtl_print.c */

void		print_mtls(t_list *material);
void		print_mtl(t_material *material);
void		print_color(t_color color);

#endif
