/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:30:39 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/25 18:02:56 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] != 0 && len != 0)
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len != 0)
	{
		dst[i] = 0;
		i++;
		len--;
	}
	return (dst);
}
