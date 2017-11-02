/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:41:39 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/13 16:16:19 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmplst;
	t_list *tmp;

	tmp = *alst;
	while (tmp)
	{
		tmplst = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmplst;
	}
	*alst = NULL;
}
