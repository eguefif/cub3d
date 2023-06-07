/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:05:08 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/04 11:46:47 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_line(t_screen *screen,
				t_display_info info, int x);

void	draw_ceiling(t_screen *screen)
{
	t_display_info	info;
	static int		x = 0;

	info.image = screen->scene.textures[SKY];
	if (x == 0)
		x = screen->scene.textures[SKY].width / 2;
	info.rows = 0;
	x += screen->player.direction_movement;
	while (info.rows < info.image.height)
	{
		info.cols = 0;
		while (info.cols < info.image.width)
		{
			display_line(screen, info, x);
			info.cols++;
		}
		info.rows++;
	}
}

static void	display_line(t_screen *screen,
				t_display_info info, int x)
{
	int		position_dst;
	int		position_src;

	position_dst = (info.cols) * (
			screen->buffer.bits_per_pixel / 8) + (
			(info.rows) * (
				screen->buffer.size_line));
	position_src = floor(
			(x + info.cols) / 0.5) * (
			info.image.bits_per_pixel / 8) + (
			floor(info.rows) * info.image.size_line);
	copy_byte_to_image(screen->buffer.start_area_ptr + position_dst,
		info.image.start_area_ptr + position_src);
}
