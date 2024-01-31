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

#include <get_next_line.h>

char *get_next_line(int fd)
{
	void		*buff;
	static long	lsize;
	char		*line;

	buff = NULL;
	lsize = 0;
	bsize = 5;
	if (read(fd, buff, 0) < 0 || fd < 0)
		return NULL;
	buff = malloc(sizeof(char) * bsize);
	read(fd, buff, bsize);
	if (0 > buf_checker((char *)buff))
	{
		lsize += buf_checker((char *)buff, bsize);
		line = malloc(sizeof(char) * lsize);
	}
		

	return 
}