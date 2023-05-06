/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 08:58:37 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/04 10:05:05 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		cleanup(t_convspe *cs,
					char **strs,
					char *final_str,
					int arg_count);
static int		print_finalstr(const char *st);

int	ft_printf(const char *str, ...)
{
	int			count;
	va_list		arg;
	char		**csstrings;
	char		*final_string;
	t_convspe	*parsed_cs;

	count = count_convspe(str);
	if (count > 0)
	{
		parsed_cs = parsing(str, count);
		va_start(arg, str);
		csstrings = csstring_builder(parsed_cs, arg, count);
		final_string = build_finalstr(str, csstrings, count);
		count = print_finalstr(final_string);
		va_end(arg);
		cleanup(parsed_cs, csstrings, final_string, count_convspe(str));
	}
	else
	{
		count = print_finalstr(str);
	}
	return (count);
}

static int	print_finalstr(const char *st)
{
	int		size;

	size = ft_strlen(st);
	ft_putstr(st);
	return (size);
}

static void	cleanup(t_convspe *cs, char **strs, char *final_str, int arg_count)
{
	free(final_str);
	clean_memory(strs, arg_count);
	clean_s_convspe(cs, arg_count);
}
