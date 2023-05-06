/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csstring_builder_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:29:58 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/05 10:11:57 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_zero(char *str, int size);
static void	fill_space(char *str, int size);

char	*place_content(char *content, char *str, t_convspe cs)
{
	size_t	s_str;
	size_t	s_content;
	int		position;

	position = 0;
	if (str != NULL)
		s_str = ft_strlen(str);
	s_content = ft_strlen(content);
	if (s_str >= s_content && str != NULL)
	{
		if (ft_strchr(cs.flags, '-'))
		{
			ft_strncpy(str, content, s_content);
		}
		else
		{
			position = s_str - s_content;
			ft_strncpy(&str[position], content, s_content);
		}
		return (str);
	}
	return (content);
}

char	*providing_string(t_convspe cs, va_list arg)
{
	int		size;
	char	*str;

	size = cs.length;
	if (ft_strchr(cs.flags, '*'))
		size = va_arg(arg, int);
	if (size == 0)
		return (NULL);
	str = ft_strnew(size + 1);
	if (str == NULL)
	{
		ft_putendl("Can't allocate memory for flag made string.");
		exit(1);
	}
	str[size] = '\0';
	if (ft_strchr(cs.flags, '0')
		&& is_number(cs.type) == 1
		&& ft_strchr(cs.flags, '-') == NULL
		&& cs.precision == 0)
		fill_zero(str, size);
	else
		fill_space(str, size);
	return (str);
}

int	is_number(char *type)
{
	if (ft_strchr(type, 'd')
		|| ft_strchr(type, 'u')
		|| ft_strchr(type, 'i')
		|| ft_strchr(type, 'x')
		|| ft_strchr(type, 'X'))
		return (1);
	return (0);
}

static void	fill_space(char *str, int size)
{
	int		c;

	c = 0;
	while (c < size)
	{
		*(str + c) = 32;
		c++;
	}
}

void	fill_zero(char *str, int size)
{
	int	c;

	c = 0;
	while (c < size)
	{
		*(str + c) = '0';
		c++;
	}
}
