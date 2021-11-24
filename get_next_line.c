/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:03:11 by aamoussa          #+#    #+#             */
/*   Updated: 2021/11/24 20:00:40 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include <fcntl.h>
#include <string.h>

void	check_endl(char **next, char **line)
{
	char	*c;
	char	*tmp;

	c = NULL;
	tmp = *next;
	if (*next)
	{
		c = ft_strchr(*next, '\n');
		if (c)
		{
			*next = ft_strdup(++c);
			c[0] = '\0';
			*line = ft_strdup(tmp);
			free(tmp);
		}
		else
		{
			*line = ft_strdup(*next);
			free(*next);
			*next = NULL;
		}
	}
}

void	ft_next_line(char **next, char *ptr)
{
	if (*ptr != '\0')
	{
		if (*next != 0)
		{
			free(*next);
			*next = NULL;
		}
			*next = ft_strdup(ptr);
	}
}

void	ft_write_line(char **line, char *buff)
{
	char	*tmp;
	char	*ok;

	tmp = *line;
	ok = NULL;
	if (!(*line))
	{	
		*line = ft_strdup("");
		ok = *line;
	}
	*line = ft_strjoin(*line, buff);
	if (ok)
		free(ok);
	if (tmp)
		free(tmp);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*next;
	char		*line;
	char		*ptr;
	static int	read_byte;

	read_byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buff[0] = 0;
	if (next)
	{
		if (!(*next))
		{
			free(next);
			return (line);
		}
	}
	check_endl(&next, &line);
	while (!ft_strchr(line, '\n') || (!line && read_byte))
	{	
		read_byte = read(fd, buff, BUFFER_SIZE);
		buff[read_byte] = '\0';
		if (read_byte == -1)
			return (NULL);
		if (read_byte == 0)
		{		
			return (line);
		}
		ptr = ft_strchr(buff, '\n');
		if (ptr)
		{	
			ft_next_line(&next, ++ptr);
			ptr[0] = '\0';
		}
		ft_write_line(&line, buff);
	}
	return (line);
}
/*
int	main(void)
{
	char	*line;
    //int           i = 0;
    int		fd1;
	int		counter = 1;

	fd1 = open("test.txt", O_RDONLY);  //\n\n
	if (fd1 == -1)
		return (0);
	while (line)
	{
		line = get_next_line(fd1);
		printf("%d %s",counter, line);
		counter++;
	}
	close(fd1);
}*/
