/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_strbuilder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:26:01 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/05 07:57:21 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*build_address(va_list arg)
{
	unsigned long long	add;
	char				*temp;
	char				*address;

	add = (unsigned long long) va_arg(arg, void *);
	temp = ft_btoa(add, 16);
	address = ft_strnew(ft_strlen(temp) + 3);
	ft_strncat(address, "0x", 2);
	ft_strncat(address, temp, ft_strlen(temp));
	lowering_hex(address);
	return (address);
}
