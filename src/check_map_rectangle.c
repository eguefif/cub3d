/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_rectangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:59:45 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/06 08:04:39 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

void	check_map_rectangle(t_map map)
{
	int		counter;
	int		line_width;

	counter = 0;
	while (counter < map.height)
	{
		line_width = (int) ft_strlen(map.map[counter]);
		if (line_width != map.width)
		{
			ft_printf("Error: map is not a rectangle.\n");
			exit(0);
		}
		counter++;
	}
}
