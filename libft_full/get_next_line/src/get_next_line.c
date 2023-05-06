/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:17:52 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/06 17:50:28 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static void		clean_memory(t_chunk *first);
static size_t	get_next_chunk(int fd, t_chunk *current);
static void		make_line(t_chunk *first, char *line, int chunks_nbr);
static size_t	process_next(char *chunk, char *rest, size_t ret_value);

int	get_next_line(int fd, char *line)
{
	int		ret_value;
	int		chunk_nbr;
	t_chunk	*first;
	t_chunk	*current;
	t_chunk	*prev;

	first = NULL;
	chunk_nbr = 0;
	ret_value = 2;
	while (ret_value != 0 && ret_value != 1 && ret_value != -1)
	{
		current = (t_chunk *) malloc(sizeof(t_chunk));
		if (first == NULL)
			first = current;
		else
			prev->next = current;
		ret_value = get_next_chunk(fd, current);
		prev = current;
		chunk_nbr++;
	}
	if (ret_value >= 0)
		make_line(first, line, chunk_nbr);
	clean_memory(first);
	return (ret_value);
}

static size_t	get_next_chunk(int fd, t_chunk *current)
{
	size_t		ret_value;
	static char	rest[BUFFER_SIZE + 1] = "\0";

	ret_value = 2;
	current->next = NULL;
	if (get_size(rest) > 0)
	{
		ret_value = get_size(rest);
		copy(current->chunk, rest);
		rest[0] = '\0';
	}
	else
	{
		ret_value = read(fd, current->chunk, BUFFER_SIZE);
	}
	if (ret_value == 0)
	{
		get_last_chunk(fd, current->chunk);
	}
	else if (ret_value > 0)
	{
		ret_value = process_next(current->chunk, rest, ret_value);
	}
	return (ret_value);
}

static size_t	process_next(char *chunk, char *rest, size_t ret_value)
{
	chunk[ret_value] = '\0';
	if (is_return_line(chunk))
	{
		get_chunk_before_rl(chunk, rest);
		ret_value = 1;
	}
	else
	{
		ret_value = 2;
	}
	return (ret_value);
}

static void	clean_memory(t_chunk *first)
{
	t_chunk	*current;
	t_chunk	*next;

	current = first;
	while (current->next != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
}

static void	make_line(t_chunk *first, char *line, int chunks_nbr)
{
	int		c;
	char	*pt;
	t_chunk	*current;

	current = first;
	c = 0;
	while (c < chunks_nbr)
	{
		if (current)
		{
			pt = current->chunk;
			while (*pt)
			{
				*line = *pt;
				line++;
				pt++;
			}
			current = current->next;
			c++;
		}
	}
	*line = '\0';
}
