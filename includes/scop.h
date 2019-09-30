/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:59:35 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/31 12:38:37 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <math.h>
# ifdef __linux__
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# else
# include </Users/ygarrot/.brew/Cellar/glew/2.1.0/include/GL/glew.h>
# include </Users/ygarrot/.brew/Cellar/glfw/3.3/include/GLFW/glfw3.h>
# endif
# define GLFW_DLL
# include "../libft/includes/libft.h"
# include <stdio.h>
# include "matrix.h"

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

typedef struct	s_vector4
{
	GLfloat	x;
	GLfloat	y;
	GLfloat	z;
	GLfloat	w;
}				t_vector4;

typedef t_vector4 t_quat;
typedef struct s_mat4
{
	GLfloat		x[4];
	GLfloat		y[4];
	GLfloat		z[4];
	GLfloat		w[4];
}				t_mat4;

typedef double vector4[4];
/* struct Vertex */
/* { */
/* 	  GLfloat position[3]; */
/* 	    GLfloat normal[3]; */
/* 		  Glubyte color[4]; */
/* }; */
 
/* Vertex vertices[VERTEX_COUNT]; */
typedef struct	s_vertex
{
	t_vector3	position;
	t_vector3	normal;
	t_vector3	textures;
}				t_vertex;

typedef struct s_array
{
	void	*content;
	size_t	content_size;
	size_t	size;
}				t_array;

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
	t_array			vertices;
	t_array			indices;
	t_material		*material;
	int				smoothing_group;
}				t_face;

typedef struct	s_scop
{
	t_array	positions;
	t_array	normals;
	t_array	textures;

	t_array	indices;

	t_list		*position_list;
	t_list		*normal_list;
	t_list		*texture_list;

	t_list		*polygons;
	t_list		*materials;

	t_material	*current_material;

	char		*name;
	int			smoothing_group;
	int			vertices_nb;
	size_t pos_nb;
}				t_scop;

void	print_vector_array(t_array const array);
void	list_to_vector_array(t_list *vertex, t_array *to_fill);
/* vertex_list.c */

t_array	list_to_array(t_list *list);
t_list		*get_vertex(t_list *vertices, void *struc);
void	array_to_vertices(char **string,
		t_array *to_fill,
		t_scop *scop);


/* tlist_functions.c */

t_list *get_material_by_name(t_list *material, void *str);


/* obj_parser.c */

void		parse_obj(const t_func_dic *dic,
		char *string, t_scop *scop);
void		iter_obj(char *string, t_scop *scop);
void		string_to_int_tab(char **split, t_array *int_tab);


/* obj_set_functions1.c */
void	create_materials(char **split, void *struc);
void	set_smoothing_group(char **split, void *struc);
void	add_texture(char **split, void *struc);
void	add_normal(char **split, void *struc);
void	add_position(char **split, void *struc);

/* obj_set_functions.c */

void		use_material(char **split, void *struc);
void		create_polygon(char **split, void *struc);
void		create_vector(char **value, t_list **stack);


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

/* draw.c */
t_vector3	*get_all_polygon(t_list *polygons);
t_vector3	*get_position(t_array *array);
int			draw(t_scop *scop);
void	list_to_float_array(t_list *vertex, t_array *to_fill);

void	check_link(int shader);
void	is_shader_compile(int shader);
void	set_tmp_textures(GLuint *shader_programme);
#endif
