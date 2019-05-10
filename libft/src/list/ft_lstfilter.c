/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:34:33 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/10 12:04:48 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfilter(t_list *lst, void * struc, t_list *(*f)(t_list *elem, void *struc))
{
	t_list *new_lst;
	t_list *node;

	if (!lst)
		return (0);
	new_lst = NULL;
	while (lst)
	{
		if ((node = f(lst, struc)))
			ft_lstpushback(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
