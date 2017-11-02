/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:09:16 by ssabbah           #+#    #+#             */
/*   Updated: 2016/12/17 15:01:57 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	str = (void *)malloc(sizeof(*str) * size);
	if (str == 0)
		return (0);
	while (i < size)
	{
		((char *)str)[i] = 0;
		i++;
	}
	return (str);
}
