/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:55:07 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/05 08:15:13 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_convspe(const char *st)
{
	int		count;

	count = 0;
	while (*st != '\0')
	{
		if (*st == '%')
		{
			if (*(st + 1) == '%')
				st++;
			count++;
		}
		st++;
	}
	return (count);
}

void	lowering_hex(char *st)
{
	int		i;

	i = 0;
	while (st[i] != '\0')
	{
		st[i] = ft_tolower(st[i]);
		i++;
	}
	i++;
}

void	clean_memory(char **arg, int n)
{
	int		count;

	count = 0;
	while (count < n)
	{
		free(arg[count]);
		count++;
	}
	free(arg);
	arg = NULL;
}

void	clean_s_convspe(t_convspe *cs, int n)
{
	int		c;

	c = 0;
	while (c < n)
	{
		if (cs[c].flags != NULL)
			free(cs[c].flags);
		cs[c].flags = NULL;
		if (cs[c].type != NULL)
			free(cs[c].type);
		cs[c].type = NULL;
		cs[c].length = 0;
		c++;
	}
}
