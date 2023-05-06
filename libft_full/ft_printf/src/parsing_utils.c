/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:59:05 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/05 07:56:56 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.h"

// Count without the %
size_t	get_cs_size(char const *st)
{
	size_t	count;

	count = 0;
	while (is_typespe(*st) == 0)
	{
		count++;
		st++;
	}
	return (count + 1);
}

int	is_flag(char ch)
{
	if (ft_strchr("-*0", ch))
		return (1);
	return (0);
}

int	is_typespe(char ch)
{
	if (ft_strchr("cspdiuxX%", ch))
		return (1);
	return (0);
}

int	is_length_nbr(char ch)
{
	if ((ft_isdigit(ch) == 1) && ((ch - 48) != 0))
		return (1);
	return (0);
}

int	isthere_inttype(char *st)
{
	if (ft_strchr(st, 'd'))
		return (1);
	if (ft_strchr(st, 'i'))
		return (1);
	if (ft_strchr(st, 'u'))
		return (1);
	return (0);
}
