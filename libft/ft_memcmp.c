/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:29:42 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/25 17:57:19 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1b;
	unsigned char	*s2b;
	size_t			i;

	s1b = (unsigned char*)s1;
	s2b = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1b[i] == s2b[i])
			i++;
		else
			return (s1b[i] - s2b[i]);
	}
	return (0);
}
