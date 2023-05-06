/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 08:46:51 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/05 08:17:16 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct s_convspe
{
	char		*flags;
	int			length;
	int			precision;
	char		*type;
}				t_convspe;

// Core functions
int			ft_printf(const char *st, ...);
t_convspe	*parsing(const char *st, int argcount);
char		**csstring_builder(t_convspe *parsed_cs,
				va_list arg,
				int arg_count);
char		*build_finalstr(const char *st,
				char **csstrings,
				int arg_count);

// util functions
int			count_convspe(const char *ist);
void		clean_memory(char **arg, int n);
void		lowering_hex(char *st);
char		**divide_st(const char *st);
void		fill_zero(char *str, int size);
int			is_number(char	*type);

// building string for convertion specifiers
char		*providing_string(t_convspe cs, va_list arg);
char		*place_content(char *content, char *str, t_convspe cs);
char		*build_char(va_list arg);
char		*build_string(va_list arg, t_convspe cs);
char		*build_integer(va_list arg, t_convspe cs);
char		*build_percentage(void);
char		*build_hexadecimal(va_list arg, t_convspe cs);
char		*build_address(va_list arg);

// Parsing util functions
size_t		get_cs_size(char const *st);
int			is_flag(char ch);
int			is_typespe(char ch);
int			is_length_nbr(char ch);
void		make_cs(char const *st, size_t size, t_convspe *cs);
void		clean_s_convspe(t_convspe *cs, int n);

#endif
