/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:29:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/04/02 11:20:15 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	letternbr(int n);
static void reverse(char *st);

char	*ft_btoa(unsigned long long n, unsigned int base)
{
	char	temp[50];
	char	*nbr;
	int		c;

	c = 0;
	while (n > base && c < 48)
	{
		temp[c] = letternbr(n % base);
		n = n / base;
		c++;
	}
	temp[c] = letternbr(n);
	temp[c + 1] = '\0';
	nbr = ft_strdup(temp);
	reverse(nbr);
	return (nbr);
}

static void	reverse(char *st)
{
	char	*temp;
	size_t	size;
	size_t	c;

	size = ft_strlen(st); 
	temp = ft_strnew(size + 1);
	c = 0;
	while (c < size)
	{
		temp[c] = st[size - c - 1];
		c++;
	}
	temp[c] = '\0';
	ft_strncpy(st, temp, size);
}

static char	letternbr(int n)
{
	if (n >= 0 && n <= 9)
		return ITOC(n);
	return (n + 55);
}
