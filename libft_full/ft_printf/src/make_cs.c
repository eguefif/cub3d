/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:42:52 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/04 08:21:58 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MAX_CS_LENGTH 30
#define MAX_CH 10

static char	*get_cs_flags(char const *st, size_t size);
static int	get_cs_length(char const *st, size_t size);
static char	*get_cs_type(char const *st, size_t size);
static int	get_cs_precision(char const *st, size_t size);

void	make_cs(char const *st, size_t size, t_convspe *cs)
{
	char		*substr;

	substr = ft_strsub(st, 0, size);
	if (substr == NULL)
		exit(0);
	cs->flags = get_cs_flags(substr, size);
	cs->length = get_cs_length(substr, size);
	cs->precision = get_cs_precision(substr, size);
	cs->type = get_cs_type(substr, size);
	free(substr);
	return ;
}

static int	get_cs_precision(char const *st, size_t size)
{
	char	*pt;
	int		ret_value;
	char	temp[100];
	size_t	c;

	pt = ft_strchr(st, '.');
	if (pt == NULL)
		ret_value = 0;
	else
	{
		pt++;
		c = 0;
		while (*pt && ft_isdigit(*pt) && c < size && c < 100)
		{
			temp[c] = *pt;
			pt++;
			c++;
		}
		temp[c] = '\0';
		ret_value = ft_atoi(temp);
	}
	return (ret_value);
}

static char	*get_cs_type(char const *st, size_t size)
{
	char	temp[MAX_CH];
	char	*type;
	size_t	c;

	c = 0;
	while (*st && c < size && c < MAX_CH)
	{
		if (is_typespe(*st) == 1)
		{
			temp[c] = *st;
			c++;
		}
		st++;
	}
	temp[c] = '\0';
	type = (char *) malloc(ft_strlen(temp) + 1);
	if (type == NULL)
		exit(1);
	ft_strncpy(type, temp, c);
	return (type);
}

static int	get_cs_length(char const *st, size_t size)
{
	size_t		count;
	char		temp[35];
	int			length;

	count = 0;
	length = 0;
	while (is_length_nbr(*st) == 0 && *st != '.')
	{
		if (*st == '\0')
			break ;
		st++;
	}
	while (*st && *st != '.' && count < size && count < 35)
	{
		if (ft_isdigit(*st) == 1)
		{
			temp[count] = *st;
			count++;
		}
		st++;
	}
	temp[count] = '\0';
	length = ft_atoi(temp);
	return (length);
}

static char	*get_cs_flags(char const *st, size_t size)
{
	size_t	count;
	char	temp[MAX_CH];
	char	*flags;

	count = 0;
	while (*st && count < (MAX_CH - 1) && count < size && is_flag(*st) == 1)
	{
		temp[count] = *st;
		count++;
		st++;
	}
	temp[count] = '\0';
	flags = ft_strnew(ft_strlen(temp) + 1);
	if (flags == NULL)
		exit(1);
	ft_strncpy(flags, temp, count);
	return (flags);
}
