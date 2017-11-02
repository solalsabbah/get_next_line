/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:30:46 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/27 11:59:44 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!s2[0])
		return ((char*)s1);
	while (s1[i])
	{
		if (s1[i] == s2[0])
		{
			while (s1[i + j] == s2[j]
					&& s1[i + j] && (i + j) < len)
				j++;
			if (j == ft_strlen(s2))
				return ((char*)s1 + i);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
