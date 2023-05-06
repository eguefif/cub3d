/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:29:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/03/25 15:54:31 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*pt1;
	char		*pt2;
	size_t		count;

	pt1 = (char *) dest;
	pt2 = (char *) src;
	count = 0;
	while (count < n)
	{
		*(pt1 + count) = *(pt2 + count);
		if (*(pt1 + count) == c)
			return (pt1 + count + 1);
		count++;
	}
	return (NULL);
}
