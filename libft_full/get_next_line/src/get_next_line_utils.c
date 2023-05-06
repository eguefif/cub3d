/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:28:20 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/06 17:15:20 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_size(char *st)
{
	size_t	size;

	size = 0;
	while (*st)
	{
		st++;
		size++;
	}
	return (size);
}

int	is_return_line(char *str)
{
	while (*str != '\n' && *str != '\0')
		str++;
	if (*str == '\n')
		return (1);
	return (0);
}

void	copy(char *str1, const char *str2)
{
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
}

void	get_last_chunk(int ft, char *chunk)
{
	int		ret_value;
	char	temp;

	ret_value = read(ft, &temp, 1);
	while (ret_value != 0)
	{
		*chunk = temp;
		chunk++;
		ret_value = read(ft, &temp, 1);
	}
	*chunk = '\0';
}

void	get_chunk_before_rl(char *chunk, char *rest)
{
	char	temp[BUFFER_SIZE + 1];
	int		c;

	c = 0;
	while (chunk[c] != '\n')
	{
		temp[c] = chunk[c];
		c++;
	}
	temp[c] = '\0';
	c++;
	while (chunk[c])
	{
		*rest = chunk[c];
		c++;
		rest++;
	}
	*rest = '\0';
	copy(chunk, temp);
}
