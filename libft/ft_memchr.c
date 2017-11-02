/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:17:33 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/25 12:07:38 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	mychar;
	int				i;

	mychar = (unsigned char)c;
	i = 0;
	while (n != 0)
	{
		if (((unsigned char*)s)[i] == mychar)
			return ((void*)(s + i));
		i++;
		n--;
	}
	return (NULL);
}
