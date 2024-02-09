/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 02:51:19 by marvin            #+#    #+#             */
/*   Updated: 2024/02/09 02:51:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd)
{
	char	*stored;
	char	*line;
	char	*tmp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, line, 0) < 0)
		return (NULL);
	tmp = read_store(stored, fd);
	line = stored;
	stored = tmp;
	return (line);
}

char	*read_store(char *store, int fd)
{
	int		i;
	int		red;
	long	size;
	char	*buffer;
	char	*leftover;

	i = 0;
	size = 0;
	leftover = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (!has_new_line(store))
	{
		red = (int)read(fd, buffer, BUFFER_SIZE);
		if (red <= 0)
		{
			free(buffer);
			return (NULL);
		}
		size += red;
		leftover = malloker(store, buffer, size);
	}
	return (leftover);
}

char	*malloker(char *stor, char *buf, long siz)
{
	char	*left;
	char	*holder;
	int		i;
	int		max;

	i = 0;
	if (has_new_line(buf) == 0)
		max = BUFFER_SIZE;
	else
		max = has_new_line(buf);
	siz -= (BUFFER_SIZE - max);
	if (siz <= BUFFER_SIZE)
		stor = malloc(sizeof(char) * siz);
	else
	{

		holder = malloc(sizeof(char) * siz);
		if (!holder)
			return (NULL);
		holder = adder(holder, stor);
		free(stor);
	}
	if(!stor)
		return (NULL);
	return (adder(stor, buf));
}

char	*adder(char *sto, char *bu)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (sto)
}

int	has_new_line(char	*ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}