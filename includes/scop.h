/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:59:35 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/10 13:51:27 by ygarrot          ###   ########.fr       */
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
	int		vertices_nb;
}				t_scop;

typedef struct s_int_tab
{
	int		*tab;
	size_t	size;
}				t_int_tab;

void	parse(const t_func_dic *dic, char *string, t_scop *scop);
void	parser_iter(char *string, t_scop *scop);
void	create_vertex(char **value, void *struc);
t_list	*get_vertex(t_list *vertices, void *struc);
#endif
