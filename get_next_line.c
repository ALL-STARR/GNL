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
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, line, 0) < 0)
		return (NULL);
	line = read_store(stored, fd, &not_first);
	filler(stored, stored + has_new_line(stored));
	return (line);
}

char	*read_store(char *stor, int fd, int	*nf)
{
	static int		red = 1;
	long			size;
	char			*line;
	int				newline;

	size = 0;
	newline = 0;
	line = NULL;
	if (red == 0)
		return (NULL);
	if (*nf)
		line = holder(BUFFER_SIZE, stor, line, &newline);
	*nf = 1;
	while (red > 0 && newline == 0)
	{
		red = (int)read(fd, stor, BUFFER_SIZE);
		size += red;
		stor[red] = '\0';
		line = holder(size, stor, line, &newline);
	}
	return (line);
}

char	*holder(long size, char *stor, char *line, int *nl)
{
	int		max;
	char	*hold;
	int		i;

	i = 0;
	max = BUFFER_SIZE;
	hold = NULL;
	if (line != NULL)
		while (line[i] != '\0')
			i++;
	if (!(has_new_line(stor) == 0))
	{
		max = has_new_line(stor);
		*nl = 1;
	}
	size -= (BUFFER_SIZE - max) - *nl;
	hold = malloc(sizeof(char) * (size + i + 1));
	if (!hold)
		return (NULL);
	filler(hold, line);
	adder(hold, stor);
	free(line);
	return (hold);
}

void	adder(char *base, char *to_add)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
		i++;
	while (to_add[j] != '\0' && to_add[j] != '\n')
	{
		base[i + j] = to_add[j];
		j++;
	}
	if (to_add[j] == '\n')
	{
		base[i + j] = '\n';
		base[i + j + 1] = '\0';
	}
	else
		base[i + j] = '\0';
}

char	*filler(char *to_fill, char *fill)
{
	int	i;

	i = 0;
	if (fill == NULL)
	{
		*to_fill = '\0';
		return (to_fill);
	}
	while (fill[i] != '\0')
	{
		to_fill[i] = fill[i];
		i++;
	}
	to_fill[i] = '\0';
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
				return (i + 1);
			i++;
		}
	}
	return (0);
}
