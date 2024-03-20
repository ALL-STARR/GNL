/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:25:14 by thomvan-          #+#    #+#             */
/*   Updated: 2024/03/20 17:25:14 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# ifdef BUFFER_SIZE 
#  if BUFFER_SIZE >= 2147483647 || BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#  endif
# endif

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*read_store(char *stor, int fd, int	*nf);
char	*holder(long size, char *stor, char *line, int *nl);
char	*filler(char *to_fill, char *fill);
void	adder(char *base, char *to_add);
int		has_new_line(char	*ptr);
int		str_length(char *str);
int		eraser(char *str, int bsize);
char	*reader(int fd, char *buff, int *rd);

#endif