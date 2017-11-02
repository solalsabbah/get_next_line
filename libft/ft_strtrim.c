/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:13:39 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/27 14:58:31 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char		*str;
	size_t		bef;
	size_t		aft;
	int			i;

	if (s)
	{
		bef = count_before(s);
		aft = count_after(s);
		i = 0;
		if (bef == ft_strlen(s))
		{
			if ((str = malloc(sizeof(*str))) == 0)
				return (NULL);
			str[0] = '\0';
			return ((char*)str);
		}
		if ((str = malloc(sizeof(*str) * (ft_strlen(s) - bef - aft + 1))) == 0)
			return (NULL);
		while (bef != (ft_strlen(s) - aft))
			str[i++] = s[bef++];
		str[i] = 0;
		return ((char*)str);
	}
	return (NULL);
}
