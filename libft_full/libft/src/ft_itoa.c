/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:29:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/03/31 15:11:40 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n);
static void	st_itoa(char *nbr, int n, int size);
static void	st_itoa_neg(char *nbr, int n, int size);

char	*ft_itoa(int n)
{
	size_t	size;
	char	*nbr;
	int		modifier;

	modifier = 1;
	if (n < 0)
	{
		modifier = 2;
		n *= -1;
	}
	size = get_size(n);
	nbr = (char *) malloc(size * sizeof(char) + modifier);
	if (nbr != NULL)
	{
		if (modifier == 2)
		{
			nbr[0] = '-';
			st_itoa_neg(nbr, n, size);
		}
		else
			st_itoa(nbr, n, size);
	}
	return (nbr);
}

static int	get_size(int n)
{
	int		c;

	c = 0;
	if (n < 10 && n > -10)
		c = 1;
	else
	{
		while (n / ft_pow(10, c) >= 1)
			c++;
	}
	return (c);
}

static void	st_itoa_neg(char *nbr, int n, int size)
{
	int		count;
	int		index;

	count = 0;
	if (n < 10)
	{
		nbr[0] = '-';
		nbr[1] = ITOC(n);
		nbr[2] = '\0';
	}
	else
	{
		while (count < (size + 1))
		{
			index = (size + 1) - count - 1;
			nbr[index] = ITOC(n % 10);
			n = n / 10;
			count++;
		}
		nbr[size + 1] = '\0';
		nbr[0] = '-';
	}
}

static void	st_itoa(char *nbr, int n, int size)
{
	int		count;
	int		index;

	count = 0;
	nbr[size] = '\0';
	while (count < size)
	{
		index = size - count - 1;
		nbr[index] = ITOC(n % 10);
		n = n / 10;
		count++;
	}
}
