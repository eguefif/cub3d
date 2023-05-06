/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_str_builder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:24:36 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/05 07:58:34 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*build_char(va_list arg)
{
	char	*content;

	content = ft_strnew(2);
	if (content != NULL)
		content[0] = (char) va_arg(arg, int);
	return (content);
}

char	*build_string(va_list arg, t_convspe cs)
{
	char	*content;
	char	*temp;

	temp = va_arg(arg, char *);
	if (cs.precision == 0)
		content = ft_strdup(temp);
	else
		content = ft_strsub(temp, 0, cs.precision);
	return (content);
}

char	*build_integer(va_list arg, t_convspe cs)
{
	char	*content;
	char	*temp;
	int		nbr;

	nbr = (int) va_arg(arg, int);
	temp = ft_itoa(nbr);
	if (cs.precision > (int) ft_strlen(temp))
	{
		content = ft_strnew(cs.precision + 1);
		fill_zero(content, cs.precision);
		ft_strncpy(&content[ft_strlen(content) - ft_strlen(temp)],
			temp,
			ft_strlen(temp));
	}
	else
	{
		content = ft_strnew(ft_strlen(temp) + 1);
		ft_strncpy(content, temp, ft_strlen(temp));
	}
	return (content);
}

char	*build_percentage(void)
{
	char	*content;

	content = ft_strnew(2);
	if (content != NULL)
	{
		content[0] = '%';
		content[1] = '\0';
	}
	return (content);
}

char	*build_hexadecimal(va_list arg, t_convspe cs)
{
	char	*content;
	char	*temp;

	temp = ft_btoa((int) va_arg(arg, int), 16);
	if (cs.precision > 0)
	{
		content = ft_strnew(cs.precision + 1);
		fill_zero(content, cs.precision);
		ft_strncpy(&content[cs.precision - ft_strlen(temp)],
			temp,
			ft_strlen(temp));
	}
	else
	{
		content = ft_strnew(ft_strlen(temp) + 1);
		ft_strncpy(content, temp, ft_strlen(temp));
	}
	if (ft_strchr(cs.type, 'x'))
		lowering_hex(content);
	return (content);
}
