/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:23:38 by marvin            #+#    #+#             */
/*   Updated: 2024/02/13 15:23:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stored[BUFFER_SIZE + 1];
	char		*line;
	static int	not_first = 0;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
	{
		eraser(stored, BUFFER_SIZE);
		not_first = 0;
		return (NULL);
	}
	line = read_store(stored, fd, &not_first);
	if (!line)
	{
		not_first = 0;
		return (NULL);
	}
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
	while (bsize > 0)
	{
		str[i] = '\0';
		bsize--;
		i++;
	}
	return (1);
}
