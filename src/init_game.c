/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:36:41 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/08 10:29:21 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h" 
#include "parsing.h"

static void	init_graphic(t_screen *screen);
static void	init_color(t_screen *screen);
static int	get_color(t_screen *screen, t_color color);

void	init_game(t_screen *screen, char *path)
{
	parsing_scene(&screen->scene, path);
	parsing_map_information(screen);
	init_graphic(screen);
	init_color(screen);
	init_screen_buffer(screen);
	init_raycasting(screen);
}

void	init_graphic(t_screen *screen)
{
	screen->mlx_ptr = mlx_init();
	screen->window = mlx_new_window(
			screen->mlx_ptr,
			screen->scene.resolution.width,
			screen->scene.resolution.height,
			WINDOW_TITLE);
}

void	init_color(t_screen *screen)
{
	screen->scene.floor.rgb = get_color(screen, screen->scene.floor);
	screen->scene.ceiling.rgb = get_color(screen, screen->scene.ceiling);
	screen->scene.wall.red = 255;
	screen->scene.wall.green = 0;
	screen->scene.wall.blue = 0;
	screen->scene.wall.rgb = get_color(screen, screen->scene.wall);
}

int	get_color(t_screen *screen, t_color color)
{
	int		rgb;

	rgb = color.blue + color.green * 256 + color.red * 65536;
	return (mlx_get_color_value(screen->mlx_ptr, rgb));
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
