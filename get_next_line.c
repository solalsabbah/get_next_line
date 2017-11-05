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

// printf("je suis la\n");

#define BUF_SIZE 10

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


int		get_next_line(const int fd, char **line)
{
	int		ret;
	static char	*rem;
	char		*buf;
	char		*tmp;
	int		len;

	rem = NULL;
	line[0] = ft_strnew(BUF_SIZE);
	buf = ft_strnew(BUF_SIZE);
	tmp = ft_strnew(BUF_SIZE);
	line[0] = ft_strnew(BUF_SIZE);
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		if (ret == -1)
			return (ret);
		buf[ret] = 0;
		tmp = ft_strdup(line[0]);
		free(line[0]);
		line[0] = ft_strjoin(tmp, buf);
		free(tmp);	
		printf("tmp :  %s\n", tmp);
		printf(RED "line : %s\n" RESET , line[0]);
		if (ft_strchr(tmp, '\n') != 0)
		{
			len = ft_strchr(line[0], '\n') - line[0];
			rem = ft_strdup(ft_strchr(line[0], '\n'));
			printf(GREEN "%s\n" RESET, rem);
			printf(GREEN "%p\n" RESET, &rem);	
			printf("len %d\n", len);
		}
	}
	printf("%d\n", fd);
	return (fd);
}

int		main(int argc, char **argv)
{
	int	fd;
	char	*line;
	
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	//get_next_line(fd, &line);
	return (0);
}
