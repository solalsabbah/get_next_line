/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:26:26 by ssabbah           #+#    #+#             */
/*   Updated: 2017/11/23 16:54:51 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// 2 basic test failled but when i try it doesnt print the \n at all .. need to check that

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line.h"

int		ft_remaintoline(char **rem, char **line)
{
	int	len;

	ft_strdel(&line[0]);
	if (ft_strchr(*rem, '\n') != NULL)
	{
		len = ft_strchr(*rem, '\n') - *rem;
		line[0] = ft_strsub(*rem, 0, len);
		free(*rem);
		*rem = ft_strchr(*rem, '\n') + 1;
		return (1);
	}
	line[0] = ft_strdup(*rem);
	*rem = NULL;
	return (0);
}

int		ft_readfunction(int fd, char **rem, char **line, char *buf)
{
	int		ret;
	int		len;
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (ret);
		buf[ret] = 0;
		tmp = ft_strdup(line[0]);
		free(line[0]);
		line[0] = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(line[0], '\n') != NULL)
		{
			len = ft_strchr(line[0], '\n') - line[0];
			*rem = ft_strdup(ft_strchr(line[0], '\n') + 1); // this strdup is fucked up
			tmp = ft_strdup(line[0]);
			ft_strdel(&line[0]);
			line[0] = ft_strsub(tmp, 0, len);
			free(tmp);
			break ;
		}
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char	*rem;
	char		*buf;
	int			ret;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	line[0] = ft_strnew(BUFF_SIZE);
	if (rem != NULL)
		if ((ft_remaintoline(&rem, &line[0])) != 0)
			return (1);
	buf = ft_strnew(BUFF_SIZE);
	if ((ret = ft_readfunction(fd, &rem, &line[0], buf)) == -1)
		return (-1);
	ft_strdel(&buf);
	if (ret == 0 && ft_strlen(line[0]) == 0)
	{
		free(line[0]);
		return (0);
	}
	return (1);
}

#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(&line[0]);
		printf("new line \n");
		ft_strdel(&line);
	}
	return (0);
}
