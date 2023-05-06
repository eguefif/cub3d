/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csstring_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:53:44 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/04 13:41:23 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*build_content(t_convspe cs, va_list arg);

char	**csstring_builder(t_convspe *parsed_cs, va_list arg, int arg_count)
{
	int		c;
	char	**csstring;
	char	*str;
	char	*content;

	csstring = (char **) malloc(arg_count * sizeof(char *));
	if (csstring == NULL)
	{
		ft_putendl("Can't allocate memory for csstring.");
		exit(1);
	}
	c = 0;
	while (c < arg_count)
	{
		str = providing_string(parsed_cs[c], arg);
		content = build_content(parsed_cs[c], arg);
		if (content != NULL)
			csstring[c] = place_content(content, str, parsed_cs[c]);
		else
		{
			csstring[c] = ft_strnew(1);
		}
		c++;
	}
	return (csstring);
}

static char	*build_content(t_convspe cs, va_list arg)
{
	char	*ret_value;

	if (ft_strchr(cs.type, 'c'))
		ret_value = build_char(arg);
	else if (ft_strchr(cs.type, 's'))
		ret_value = build_string(arg, cs);
	else if (ft_strchr(cs.type, 'i')
		|| ft_strchr(cs.type, 'u') || ft_strchr(cs.type, 'd'))
		ret_value = build_integer(arg, cs);
	else if (ft_strchr(cs.type, '%'))
		ret_value = build_percentage();
	else if (ft_strchr(cs.type, 'x') || ft_strchr(cs.type, 'X'))
		ret_value = build_hexadecimal(arg, cs);
	else if (ft_strchr(cs.type, 'p'))
		ret_value = build_address(arg);
	else
		ret_value = NULL;
	return (ret_value);
}
