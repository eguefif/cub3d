/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:48:50 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 14:29:54 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_memory_cleanup(t_map map);
static void	destroy_images(t_screen *screen);

int	terminate_game(t_screen *screen)
{
	map_memory_cleanup(screen->scene.map);
	destroy_images(screen);
	mlx_destroy_window(screen->mlx_ptr, screen->window);
	return (0);
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

static void	destroy_images(t_screen *screen)
{
	int	counter;
	counter = 0;
	while (counter < NBR_TEXTURES)
	{
		mlx_destroy_image(screen->mlx_ptr, screen->scene.textures[counter].img_ptr);
		counter++;
	}
}

