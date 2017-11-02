/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:31:38 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/25 18:36:05 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	i = 0;
	s1b = (unsigned char*)s1;
	s2b = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (s1b[i] == s2b[i] && s1b[i] != '\0' && i < n - 1)
		i++;
	return (s1b[i] - s2b[i]);
}
