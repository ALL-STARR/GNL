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
	static char	stored[BUFFER_SIZE];
	static int	first = 1;
	char		*line;
	char		*tmp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, line, 0) < 0)
		return (NULL);
	line = read_store(stored, fd, &first);
	filler(stored, stored + has_new_line(stored));
	return (line);
}

char	*read_store(char *stor, int fd, int *first)
{
	int		red;
	long	size;
	char	*line;
	int		newline;

	size = 0;
	red = 1;
	newline = 0;
	while (red > 0 && !newline)
	{
		red = (int)read(fd, stor, BUFFER_SIZE);
		size += red;
		stor[red] = '\0';
		line = holder(size, stor, line, &newline);
	}
	return (line);
}

char	*holder(long size,char *stor, char *line, int *nl)
{
	int		max;
	char	*hold;

	max = BUFFER_SIZE;
	if (!(has_new_line(stor) == 0))
	{
		max = has_new_line(stor);
		*nl = 1;
	}
	size -= (BUFFER_SIZE - max);
	hold = malloc(sizeof(char) * size);
	if (!hold)
		return (NULL);
	filler(hold, line);
	adder(hold, stor);
	free(hold);
	return (hold);
}

void	adder(char *base, char *to_add)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (base && base[i] != '\0')
		i++;
	while (to_add[j] != '\0' && to_add != '\n')
	{
		base[i + j] = to_add[j];
		j++;
	}
	if (base[i + j] == '\n')
		base[i + j] = '\n';
	else
		base[i + j] = '\0';
	free(base);
}

char	*filler(char *to_fill, char *fill)
{
	int	i;

	i = 0;
	if (!fill)
	{
		*to_fill = '\0'
		return (to_fill);
	}
	while (fill[i] != '\0')
	{
		to_fill[i] = fill[i];
		i++;
	}
	return (to_fill);
}

int	has_new_line(char	*ptr)
{
	int	i;

	i = 0;
	if (ptr != 0)
	{
		while (ptr[i] != '\0')
		{
			if (ptr[i] == '\n')
				return (i);
			i++;
		}
	}
	return (0);
}
