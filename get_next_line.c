/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:25:21 by thomvan-          #+#    #+#             */
/*   Updated: 2024/03/20 17:25:21 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stored[BUFFER_SIZE + 1];
	char		*line;
	int			not_first;

	line = NULL;
	not_first = str_length(stored);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
	{
		eraser(stored, BUFFER_SIZE);
		return (NULL);
	}
	line = read_store(stored, fd, &not_first);
	if (!line && eraser(stored, BUFFER_SIZE))
		return (NULL);
	filler(stored, stored + str_length(stored));
	return (line);
}

int	str_length(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (i);
}

int	eraser(char *str, int bsize)
{
	int	i;

	i = 0;
	while (bsize >= 0)
	{
		str[i] = '\0';
		bsize--;
		i++;
	}
	return (1);
}

char	*reader(int fd, char *buff, int *rd)
{
	*rd = read(fd, buff, BUFFER_SIZE);
	buff[*rd] = '\0';
	if (*rd == 0 && eraser(buff, BUFFER_SIZE))
		return (NULL);
	if (*rd < 0 && eraser(buff, BUFFER_SIZE))
		return (NULL);
	return (buff);
}
