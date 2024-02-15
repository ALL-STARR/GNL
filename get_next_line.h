/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:28:00 by marvin            #+#    #+#             */
/*   Updated: 2024/02/15 16:28:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*read_store(char *stor, int fd, int	*nf);
char	*holder(long size, char *stor, char *line, int *nl);
char	*filler(char *to_fill, char *fill);
void	adder(char *base, char *to_add);
int		has_new_line(char	*ptr);

#endif