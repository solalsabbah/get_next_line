/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:23:59 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/25 17:49:09 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;

	new_list = NULL;
	if (lst && f)
	{
		new_list = (*f)(lst);
		if (new_list && lst->next)
			new_list->next = ft_lstmap(lst->next, f);
	}
	return (new_list);
}
