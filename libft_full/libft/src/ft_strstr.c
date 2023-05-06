/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:29:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/03/25 15:58:45 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	size;
	char	*hay;

	hay = (char *) haystack;
	size = ft_strlen(needle);
	while (*hay != '\0')
	{
		if (*hay == *needle)
			if (ft_strncmp(hay, needle, size - 1) == 0)
				return (hay);
		hay++;
	}
	return (NULL);
}
