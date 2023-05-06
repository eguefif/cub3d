/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:29:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/03/31 15:15:49 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ctoi(char c);

int	ft_atoi(const char *nptr)
{
	int		number;
	int		size;
	int		count;
	int		rank;
	int		modifier;

	size = (int) ft_strlen(nptr);
	modifier = 0;
	if (nptr[0] == '-')
		modifier = 1;
	count = 0;
	number = 0;
	while (count < (size - modifier))
	{
		rank = size - count - 1 - modifier;
		number += ctoi(nptr[count + modifier]) * ft_pow(10, rank);
		count++;
	}
	if (modifier == 1)
		number *= -1;
	return (number);
}

static int	ctoi(char c)
{
	return (c - 48);
}
