/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:18:16 by marvin            #+#    #+#             */
/*   Updated: 2024/01/22 23:18:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE

# define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*read_store(char *stored, int fd);
int		no_new_line_check(char *stored);
char	*copier(char *add, char *store, char *buff, int b);
char	*adder(char *buffer, char *stored, long s, int red);

#endif