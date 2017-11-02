/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:30:09 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/25 18:01:23 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	i = 0;
	s1b = (unsigned char*)s1;
	s2b = (unsigned char*)s2;
	while (s1b[i] == s2b[i] && s1b[i] != 0 && s2b[i] != 0)
		i++;
	if (s1b[i] == 0 && s2b[i] == 0)
		return (0);
	return (s1b[i] - s2b[i]);
}
