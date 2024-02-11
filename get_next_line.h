#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE

# define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*read_store(char *store, int fd);
char	*holder(char *stor, char *buf, long siz);
void	filler(char *to_fill, char *filler, long siz);
char	*adder(char *hold, char *stored, char *buffer, int maximum);
int		has_new_line(char	*ptr);

#endif