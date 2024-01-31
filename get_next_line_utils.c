/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:15:21 by marvin            #+#    #+#             */
/*   Updated: 2024/01/22 23:15:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static	char	*stored;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, line, 0) < 0)
		return (NULL);
	stored = NULL;
	read_store(&stored, fd, line);
	line = stored;
	return (line);
}

void	read_store(char **stored, int fd, char *line)
{
	char	*buf;
	int		red;
	long 	size;

	buf = NULL;
	size = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return;
	while (new_line_check(*stored) && red != 0)
	{
		red = (int)read(fd , buf, BUFFER_SIZE);
		if ((*stored == NULL && red == 0) || red < 0)
		{
			free(buf);
			return ;
		}
		buf[red] = '\0';
		size += red;
		adder(buf, stored, size, red; line);
	}
}

void	adder(char *buffer, char *stored, long s, int red, char *lin)
{
	char	*added;
	int		i;
	int		bs;

	i = red;
	bs = 0;
	while (buffer[j] != '\n' && buffer[j] != '\0')
	{
		bs++;
		i--;
	}	
	s -= i;
	added = malloc(sizeof(char) * s);
	if (!added)
		return ;
	copier(added, stored, buffer, bs);
	return ;
} 

void	copier(char *add, char *store, char *buff, int b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (store[i] != '\0')
	{
		add[i] = store[i];
		i++;
	}
	while (b > 0)
	{
		add[i + j] = buff[j];
		j++;
		b--;
	}
	free (store);
	store = add;
	free (add);
	return ;
}