/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:59:35 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/09 13:01:39 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <math.h>
# include "../libft/includes/libft.h"

typedef struct	s_func_dic
{
	char		*key;
	void		(*func)(char *, void *);
}				t_func_dic;


typedef struct	s_vertex
{
	double	x;
	double	y;
	double	z;
	double	w;
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

typedef struct	s_scop
{
	t_list	*vertices;
}				t_scop;

void	create_vertex(char *value, void *structure);

void	parse(const t_func_dic *dic, char *string, t_scop *scop);
void parser_iter(char *string, t_scop *scop);
void	create_vertex(char *value, void *struc);
#endif
