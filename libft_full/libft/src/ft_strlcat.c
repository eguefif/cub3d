/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:29:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/03/25 10:57:52 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	size_dst;
	size_t	total_size;

	total_size = ft_strlen(dst) + ft_strlen(src);
	size_dst = ft_strlen(dst);
	c = 0;
	while ((size_dst + c) < size && src[c] != '\0')
	{
		dst[size_dst + c] = src[c];
		c++;
	}
	dst[size] = '\0';
	return (total_size);
}
