/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:32:24 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/25 18:14:57 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_words(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static int		ft_nb_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		x;
	int		nb_words;

	if (!str)
		return (NULL);
	nb_words = ft_nb_words((char *)str, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	x = 0;
	while (nb_words--)
	{
		while (*str == c && *str)
			str++;
		tab[x] = ft_strsub((char *)str, 0, ft_nb_char((char *)str, c));
		if (!tab[x])
			return (NULL);
		str = str + ft_nb_char((char *)str, c);
		x++;
	}
	tab[x] = NULL;
	return (tab);
}
