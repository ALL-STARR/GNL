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

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, line, 0) < 0)
		return (NULL);
	stored = NULL;
	tmp = read_store(stored, fd);
	printf("tmp is %s\n", tmp);
	line = stored;
	stored = tmp;
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
	red = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
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
		printf("lefto is %s\n", lefto);
	}
	return (lefto);
}

char	*adder(char *buffer, char *stored, long s, int red)
{
	char	*added;
	int		bnl;

	bnl = 0;
	while (buffer[bnl] != '\n' && buffer[bnl] != '\0' && red--)
		bnl++;
	s -= (BUFFER_SIZE - bnl);
	added = malloc(sizeof(char) * s);
	if (!added)
		return (NULL);
	return (copier(added, stored, buffer, bnl));
}

char	*copier(char *add, char *store, char *buff, int b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (store != NULL)
	{
		while (store[i] != '\0')
		{
			add[i] = store[i];
			i++;
		}
		free (store);
	}
	while (b > 0)
	{
		add[i + j] = buff[j];
		j++;
		b--;
	}
	add[i + j] = '\0';
	printf("add is %s ", add);
	store = add;
	printf("and buff is %s\n", buff + j);
	return (buff + j);
}

int	no_new_line_check(char *stored)
{
	int	i;

	i = 0;
	if (stored == NULL)
		return (1);
	while (stored[i] != '\0')
	{
		if (stored[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
