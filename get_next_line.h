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
char	*holder(long size,char *stor, char *line, int *nl);
char	*filler(char *to_fill, char *fill);
void	adder(char *base, char *to_add);
int		has_new_line(char	*ptr);

#endif