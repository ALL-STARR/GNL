/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:51:57 by marvin            #+#    #+#             */
/*   Updated: 2024/02/09 13:51:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	has_new_line(char	*ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*adder(char *hold, char *stored, char *buffer, int maximum)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stored[i] != '\0')
	{
		hold[i] = stored[i];
		i++;
	}
	while (buffer[i] != '\0' && maximum > 0)
	{
		hold[i + j] = buffer[j];
		j++;
		maximum--;
	}
	hold[i + j] = '\0';
	return (buffer + j);
}