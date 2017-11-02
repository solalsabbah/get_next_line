/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:26:26 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/02 19:04:26 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

#define BUF_SIZE 10

int		check_line(char *)

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUF_SIZE + 1];
	static char		*rem;
	char			*str;
	char			*str2;
	int				i;
	int				j;

	i = 0;
	str = malloc(sizeof(char) * BUF_SIZE + 1);
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		buf[ret] = 0;
		if (i == 0)
			str = ft_strcpy(str, buf);
		else
			str2 = ft_strjoin(str, buf);
		str = str2;	
		j = ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n'));
		ft_strdel(&str);
		i++;
	}
	return (fd);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[2], O_RDONLY);
	get_next_line(fd, &line);
	return (0);
}
