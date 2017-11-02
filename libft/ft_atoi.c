/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:59:30 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/25 17:51:15 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	i;
	long int	p;
	long long	nb;

	p = 1;
	nb = 0;
	i = 0;
	while ((str[i] == '\n' || str[i] == ' ' || str[i] == '\r'
				|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
	{
		p = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return ((int)(nb * p));
}
