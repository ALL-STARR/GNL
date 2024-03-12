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

char	*read_store(char *stor, int fd, int	*nf)
{
	static int		red = 1;
	long			size;
	char			*line;
	int				newline;

	size = 0;
	newline = 0;
	line = NULL;
	if (*nf && red > 0)
		line = holder(BUFFER_SIZE, stor, line, &newline);
	*nf = 1;
	while (red > 0 && newline == 0)
	{
		red = (int)read(fd, stor, BUFFER_SIZE);
		if (red == 0)
			return (line);
		if ((red < 0 && eraser(stor, BUFFER_SIZE)))
			return (NULL);
		size += str_length(stor);
		stor[red] = '\0';
		line = holder(size, stor, line, &newline);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*holder(long size, char *stor, char *lin, int *nl)
{
	long		max;
	char		*hold;
	long		i;

	i = 0;
	max = 0;
	hold = NULL;
	if (lin != NULL)
		i = str_length(lin);
	if (has_new_line(stor))
		*nl = 1;
	hold = malloc(sizeof(char) * (size + i + 1));
	if (!hold)
		return (NULL);
	filler(hold, lin);
	adder(hold, stor);
	free(lin);
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
	int	j;

	j = 0;
	while (ptr[j] != '\n' && ptr[j] != '\0')
		j++;
	if (ptr[j] == '\n')
		return (1);
	return (0);
}
