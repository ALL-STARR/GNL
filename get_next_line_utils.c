/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:25:03 by thomvan-          #+#    #+#             */
/*   Updated: 2024/03/20 17:25:03 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_store(char *stor, int fd, int *nf)
{
	int		red;
	long	size;
	char	*line;

	size = 0;
	line = NULL;
	red = 1;
	if (*nf && stor[0])
	{
		line = holder(str_length(stor), stor, line, &red);
		size += str_length(line);
	}
	while (red > 0)
	{
		if (reader(fd, stor, &red) == NULL)
			return (line);
		size += str_length(stor);
		line = holder(size, stor, line, &red);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*holder(long size, char *stor, char *lin, int *nl)
{
	char	*hold;

	hold = NULL;
	if (has_new_line(stor))
		*nl = -1;
	hold = malloc(sizeof(char) * (size + 1));
	if (!hold)
		return (NULL);
	filler(hold, lin);
	adder(hold, stor);
	if (lin != NULL)
	{
		eraser(lin, str_length(lin));
		free(lin);
	}
	lin = NULL;
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

int	has_new_line(char *ptr)
{
	int	j;

	j = 0;
	while (ptr[j] != '\n' && ptr[j] != '\0')
		j++;
	if (ptr[j] == '\n')
		return (1);
	return (0);
}
