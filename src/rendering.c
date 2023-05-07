/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:27:21 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/06 19:20:31 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	swap_frame_screen(t_screen *screen);

void	rendering_game(t_screen *screen)
{
	t_raycasting_vertical_line	line;
	int							counter;

	line.top_color = screen->scene.ceiling;
	line.mid_color = screen->scene.wall;
	line.bot_color = screen->scene.floor;
	line.x = 250;
	line.y_top = 100;
	line.y_bot = 500;
	counter = 0;
	while (counter < 250)
	{
		line.x = 250 + counter;
		draw_raycasting_vertical_line(screen, line);
		counter++;
	}
	swap_frame_screen(screen);
}

void	swap_frame_screen(t_screen *screen)
{
	mlx_put_image_to_window(screen->mlx_ptr,
		screen->window,
		screen->buffer.img_ptr,
		0,
		0);
	mlx_destroy_image(screen->mlx_ptr,
		screen->buffer.img_ptr);
	init_screen_buffer(screen);
}
