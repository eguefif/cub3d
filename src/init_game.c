/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:36:41 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/05 19:31:27 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h" 
#include "parsing.h"

static void	init_graphic(t_screen *screen);

void	init_game(t_screen *screen, char *path)
{
	parsing_scene(&screen->scene, path);
	parsing_map_information(screen);
	init_graphic(screen);
	init_color(screen);
	init_wall_textures(screen);
	init_animations(screen);
	init_npc_animation(screen);
	init_sprites(screen);
	init_screen_buffer(screen);
	init_raycasting(screen);
	screen->pause = 0;
}

void	init_mouse(t_screen *screen)
{
	screen->mouse.x = screen->scene.resolution.width / 2;
	screen->mouse.y = screen->scene.resolution.width / 2;
	mlx_mouse_move(screen->mlx_ptr, screen->window,
		screen->mouse.x, screen->mouse.y);
}

void	init_graphic(t_screen *screen)
{
	screen->mlx_ptr = mlx_init();
	screen->window = mlx_new_window(
			screen->mlx_ptr,
			screen->scene.resolution.width,
			screen->scene.resolution.height,
			WINDOW_TITLE);
	mlx_do_key_autorepeaton(screen->mlx_ptr);
}

void	init_screen_buffer(t_screen *screen)
{
	screen->buffer.img_ptr = mlx_new_image(screen->mlx_ptr,
			screen->scene.resolution.width,
			screen->scene.resolution.height);
	screen->buffer.start_area_ptr = mlx_get_data_addr(screen->buffer.img_ptr,
			&screen->buffer.bits_per_pixel,
			&screen->buffer.size_line,
			&screen->buffer.endian);
}
