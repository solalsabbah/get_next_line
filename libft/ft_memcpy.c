/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:03:31 by ssabbah           #+#    #+#             */
/*   Updated: 2016/12/17 10:48:43 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	while (n != 0)
	{
		s1[i] = s2[i];
		i++;
		n--;
	}
	return (dst);
}
