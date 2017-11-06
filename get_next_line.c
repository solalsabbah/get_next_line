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

/// pk le buff ne repart pas du bébut du fichier ?
/// tmp et buf s'écrase à certain moment 

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

#define BUFF_SIZE 10

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int		ft_remaintoline(char **rem, char **line)
{
	int	len; 
	
	if (ft_strchr(*rem, '\n') != NULL)
	{
		len = ft_strchr(*rem, '\n') - *rem;
		line[0] = ft_strsub(*rem, 0, len);
		*rem = ft_strchr(*rem, '\n') + 1;
		return (1);
	}
	line [0] = ft_strdup(*rem);
	*rem = NULL;
	return (0);
}

int		ft_readfunction(int fd, char **rem, char **line, char *buf)
{
	int 	ret;
	int	len; 
	char	*tmp;
		
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = 0;
		printf("buf >> %s << \n", buf);
		tmp = ft_strdup(line[0]);
		free(line[0]);
		line[0] = ft_strjoin(tmp, buf); // pb join tmp et buf
		printf("tmp : %s\n", tmp); // understanding tmp & buf
		//printf(GREEN ">> %s <<\n" RESET, line[0]); //// print line
		free(tmp);
		if (ft_strchr(line[0], '\n') != NULL)
		{
			len = ft_strchr(line[0], '\n') - line[0];
			*rem = ft_strdup(ft_strchr(line[0], '\n') + 1);
			printf(BLUE "je rentre ici\n"RESET);
			//printf("rem 1 %s\n", *rem); /// print remaining 
			tmp = ft_strdup(line[0]);
			free(line[0]);
			line[0] = ft_strsub(tmp, 0, len);
			//printf(BLUE ">> tmp %s\n <<" RESET, tmp); // print tmp
			free(tmp);
			break ; 
		}
	}
	return (ret);

}


int		get_next_line(const int fd, char **line)
{
	static char	*rem = NULL;
	char		*buf;
	int		ret;
	
	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	line[0] = ft_strnew(BUFF_SIZE);
	if (rem != NULL)
		if ((ft_remaintoline(&rem, &line[0])) != 0)
		{
			//printf("line" CYAN ">> %s<<\n" RESET, line[0]); // print final line
			return (1);
		}
	//printf(">> rem %s <<\n", rem); // print remaing 
	buf = ft_strnew(BUFF_SIZE);
	if ((ret = ft_readfunction(fd, &rem, &line[0], buf)) == -1)
		return (-1);
	//printf(RED "%s\n" RESET, line[0]); // print final line
	free(buf);
	if (ret == 0 && ft_strlen(line[0]) == 0)
		return (0);
	//printf("line" GREEN ">> %s<<\n" RESET, line[0]);
	return (1);
}

int		main(int argc, char **argv)
{
	int	fd;
	char	*line;
	
	fd = open(argv[1], O_RDONLY);
	printf("gnl : %d\n", get_next_line(fd, &line));
	printf("-----------------\n");
	printf("gnl : %d\n", get_next_line(fd, &line));
	printf("-----------------\n");
	printf("gnl : %d\n", get_next_line(fd, &line));
	printf("-----------------\n");
	printf("gnl : %d\n", get_next_line(fd, &line));
	printf("-----------------\n");
	printf("gnl : %d\n", get_next_line(fd, &line));

		return (0);
}
