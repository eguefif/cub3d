/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:57:40 by eguefif           #+#    #+#             */
/*   Updated: 2023/03/23 21:34:28 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memset(void *s, int c, size_t n)
{
	long unsigned int		count;
	char					*pt;

	count = 0;
	pt = (char *) s;
	while (count < n)
	{
		pt[count] = c;
		count++;
	}
	s = pt;
}
