/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalstr_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:15:08 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/05 07:59:16 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		**divide_st(const char *st);
static void	remove_cs(char *st);
static char	*assemble(char **st_chunks, char **csstrings, int arg_count);
static int	finalst_getsize(char **st_chunks, char **csstrings, int argc_count);

char	*build_finalstr(const char *st,
		char **csstrings,
		int arg_count)
{
	char	*final_str;
	char	**st_chunks;
	int		c;

	st_chunks = divide_st(st);
	final_str = assemble(st_chunks, csstrings, arg_count);
	c = 0;
	while (c < arg_count + 1)
	{
		free(st_chunks[c]);
		st_chunks[c] = NULL;
		c++;
	}
	return (final_str);
}

char	**divide_st(const char *st)
{
	char	*copy;
	char	**st_chunks;

	copy = ft_strnew(ft_strlen(st) + 1);
	if (copy == NULL)
	{
		ft_putendl("Can't allocate memory to copy format string in divide_st.");
		exit(1);
	}
	ft_strncpy(copy, st, ft_strlen(st));
	remove_cs(copy);
	st_chunks = ft_strsplit(copy, '%');
	return (st_chunks);
}

static void	remove_cs(char *st)
{
	char	*temp;
	int		c;
	int		c2;

	temp = ft_strnew(ft_strlen(st) + 1);
	c = 0;
	c2 = 0;
	while (*(st + c))
	{
		if (*(st + c) == '%')
		{
			*(temp + c2) = *(st + c);
			c++;
			c = (c + get_cs_size((st + c)));
			c2++;
		}
		else
		{
			*(temp + c2) = *(st + c);
			c2++;
			c++;
		}
	}
	ft_strncpy(st, temp, ft_strlen(temp) + 1);
	free(temp);
}

static char	*assemble(char **st_chunks, char **csstrings, int arg_count)
{
	int		size;
	char	*final_str;
	int		c;

	size = finalst_getsize(st_chunks, csstrings, arg_count);
	final_str = ft_strnew(size + 1);
	if (final_str == NULL)
	{
		ft_putendl("Can't allocate memory to build final string.");
		exit(1);
	}
	c = 0;
	while (c < arg_count)
	{
		if (st_chunks[c] != NULL)
			ft_strncat(final_str, st_chunks[c], ft_strlen(st_chunks[c]));
		ft_strncat(final_str, csstrings[c], ft_strlen(csstrings[c]));
		c++;
	}
	if (st_chunks[c] != NULL)
		ft_strncat(final_str, st_chunks[c], ft_strlen(st_chunks[c]));
	return (final_str);
}

static int	finalst_getsize(char **st_chunks, char **csstrings, int arg_count)
{
	int		c;
	int		size;

	c = 0;
	size = 0;
	while (c < arg_count)
	{
		size += ft_strlen(st_chunks[c]);
		size += ft_strlen(csstrings[c]);
		c++;
	}
	if (st_chunks[c] != NULL)
		size += ft_strlen(st_chunks[c]);
	return (size);
}
