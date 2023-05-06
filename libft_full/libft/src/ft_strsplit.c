/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:29:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/04 12:26:34 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_count(char const *s, char c);
static void	split(char **pt, char const *s, char c);

char	**ft_strsplit(char const *s, char c)
{
	char	**pt;
	int		count;

	count = get_count(s, c);
	pt = (char **) malloc(count * sizeof(char *));
	if (pt != NULL)
	{
		if (count == 0)
			*pt = ft_strdup(s);
		else
			split(pt, s, c);
	}
	return (pt);
}

static int	get_count(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count + 1);
}

static void	split(char **pt, char const *s, char c)
{
	char	*temp;
	int		count;
	int		count2;

	temp = ft_strnew(ft_strlen(s) + 1);
	count = 0;
	count2 = 0;
	while (*s)
	{
		if (*s == c)
		{
			pt[count] = ft_strdup(temp);
			count++;
			temp = ft_strnew(ft_strlen(s) + 1);
			count2 = 0;
		}
		else
		{
			*(temp + count2) = *s;
			count2++;
		}
		s++;
	}
	pt[count] = ft_strdup(temp);
}
