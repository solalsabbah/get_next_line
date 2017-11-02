/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:36:05 by ssabbah           #+#    #+#             */
/*   Updated: 2017/05/04 12:20:19 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		isneg;

	isneg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		isneg = 1;
		n = -n;
	}
	len = int_len(n) + isneg;
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	str[len] = 0;
	while (len-- >= 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (isneg == 1)
		str[0] = '-';
	return (str);
}
