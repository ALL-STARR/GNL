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
	free(stored);
	stored = tmp;
	return (line);
}

char	*read_store(char *store, int fd)
{
	int		i;
	int		red;
	long	size;
	char	*buffer;
	char	*lefto;

	i = 0;
	size = 0;
	red = 1;
	lefto = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (has_new_line(store) == 0 && red > 0)
	{
		red = (int)read(fd, buffer, BUFFER_SIZE);
		if (red <= 0)
			free(buffer);
		size += red;
		buffer[red] = '\0';
		lefto = holder(store, buffer, size);
	}
	return (lefto);
}

char	*holder(char *stor, char *buf, long siz)
{
	char	*holder;
	int		max;
	char	*leftover;

	if (has_new_line(buf) == 0)
		max = BUFFER_SIZE;
	else
		max = has_new_line(buf);
	siz -= (BUFFER_SIZE - max);
	if (siz <= BUFFER_SIZE)
	{
		stor = NULL;
		holder = malloc(sizeof(char) * siz);
	}
	else
		holder = malloc(sizeof(char) * siz);
	if(!holder)
		return (NULL);
	leftover = adder(holder, stor, buf, siz);
	filler(stor, holder, siz);
	return (leftover);
}

void	filler(char *to_fill, char *filler, long siz)
{
	int	i;

	i = 0;
	while (filler[i] != '\0')
		i++;
	if (siz <= BUFFER_SIZE)
		to_fill = malloc(sizeof(char) * i);
	else
	{
		free(to_fill);
		to_fill = malloc(sizeof(char) * i);
	}
	if (!to_fill)
		return ;
	i = 0;
	while (filler[i] != '\0')
	{
		to_fill[i] = filler[i];
		i++;
	}
	free(filler);
	return ;
}
