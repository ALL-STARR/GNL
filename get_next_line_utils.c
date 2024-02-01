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

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, line, 0) < 0)
		return (NULL);
	stored = NULL;
	tmp = read_store(stored, fd);
	line = stored;
	stored = tmp;
	free (tmp);
	return (line);
}

char	*read_store(char *stored, int fd)
{
	char	*buf;
	int		red;
	long	size;
	char	*lefto;

	buf = NULL;
	size = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	while (no_new_line_check(stored) && red != 0)
	{
		red = (int)read(fd, buf, BUFFER_SIZE);
		if ((stored == NULL && red == 0) || red < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[red] = '\0';
		size += red;
		lefto = adder(buf, stored, size, red);
	}
	return (lefto);
}

char	*adder(char *buffer, char *stored, long s, int red)
{
	char	*added;
	int		bnl;

	bnl = 0;
	while (buffer[bnl] != '\n' && buffer[bnl] != '\0')
		bnl++;
	s -= (BUFFER_SIZE - bnl);
	added = malloc(sizeof(char) * s);
	if (!added)
		return ;
	return (copier(added, stored, buffer, bnl));
}

char	*copier(char *add, char *store, char *buff, int b)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	j = 0;
	while (store[i] != '\0')
	{
		add[i] = store[i];
		i++;
	}
	leftover = malloc(sizeof(char) * (b + 1));
	while (b > 0)
	{
		add[i + j] = buff[j];
		j++;
		b--;
	}
	add[i + j] = '\0';
	store = add;
	leftover = buff + j;
	free (add);
	return (leftover);
}

int	no_new_line_check(char *stored)
{
	int	i;

	i = 0;
	while (stored[i] != '\0')
	{
		if (stored[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
