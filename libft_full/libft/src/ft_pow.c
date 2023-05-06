/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:01:46 by eguefif           #+#    #+#             */
/*   Updated: 2023/03/31 15:02:03 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int n, int p)
{
	int		count;
	int		result;

	count = 0;
	result = 1;
	while (count < p)
	{
		result *= n;
		count++;
	}
	return (result);
}
