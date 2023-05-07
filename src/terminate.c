/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:48:50 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/06 19:19:57 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_memory_cleanup(t_map map);

void	terminate_game(t_screen *screen)
{
	map_memory_cleanup(screen->scene.map);
	mlx_destroy_window(screen->mlx_ptr, screen->window);
}

void	map_memory_cleanup(t_map map)
{
	int		counter;

	counter = 0;
	while (counter < map.height)
	{
		free(map.map[counter]);
		counter++;
	}
	free(map.map);
}
