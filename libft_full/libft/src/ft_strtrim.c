/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:29:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/03/26 12:20:36 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char s);
static int	count_start(char const *s);
static int	count_end(char const *s);
static int	get_count(char const *s);

char	*ft_strtrim(char const *s)
{
	int		trim_count;
	char	*pt;
	int		start;
	size_t	size;

	trim_count = get_count(s);
	size = ft_strlen(s) - trim_count;
	pt = (char *) malloc(size + 1);
	if (pt == NULL)
		return (pt);
	start = count_start(s);
	pt = ft_strsub(s, start, size);
	pt[size + 1] = '\0';
	return (pt);
}

static int	is_whitespace(char s)
{
	if (s == 32 || s == '\n' || s == '\t')
		return (1);
	return (0);
}

static int	count_start(char const *s)
{
	size_t	count;
	size_t	size;

	count = 0;
	size = ft_strlen(s);
	while (is_whitespace(*s) == 1 && count < size)
	{
		s++;
		count++;
	}
	return (count);
}

static int	count_end(char const *s)
{
	size_t		count;
	size_t		size;
	char const	*pt;

	size = ft_strlen(s);
	pt = (s + size - 1);
	count = 0;
	while (is_whitespace(*pt) == 1 && count < size)
	{
		pt--;
		count++;
	}
	return (count);
}

static int	get_count(char const *s)
{
	int		count;

	count = 0;
	count += count_start(s);
	count += count_end(s);
	return (count);
}
