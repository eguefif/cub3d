/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:48:06 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/05 07:56:32 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_convspe	*parsing(char const *st, int argcount)
{
	int			i;
	size_t		size;
	t_convspe	*cs;

	cs = (t_convspe *) malloc(argcount * sizeof(t_convspe));
	i = 0;
	while (i < argcount && *st)
	{
		if (*st == '%')
		{
			st++;
			if (*st != '\0')
			{
				size = get_cs_size(st);
				make_cs(st, size, &cs[i]);
				i++;
			}
			if (*(st + size) == '\0')
				break ;
			st += size;
		}
		else
			st++;
	}
	return (cs);
}
