/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:48:50 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/22 17:47:29 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_memory_cleanup(t_map map);
static void	destroy_images(t_screen *screen);
static void	destroy_animated_sprites(t_screen *screen);

int	terminate_game(t_screen *screen)
{
	map_memory_cleanup(screen->scene.map);
	destroy_images(screen);
	mlx_mouse_show(screen->mlx_ptr, screen->window);
	mlx_destroy_window(screen->mlx_ptr, screen->window);
	destroy_animated_sprites(screen);
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
		mlx_destroy_image(
			screen->mlx_ptr, screen->scene.textures[counter].img_ptr);
		counter++;
	}
}

static void	destroy_animated_sprites(t_screen *screen)
{
	int		sprite_counter;

	sprite_counter = 0;
	while (sprite_counter < screen->scene.images_sprite_count)
	{
		mlx_destroy_image(screen->mlx_ptr, screen->scene.sprite_images[
				sprite_counter]->img_ptr);
		free(screen->scene.sprite_images[sprite_counter]);
		sprite_counter++;
	}
}
