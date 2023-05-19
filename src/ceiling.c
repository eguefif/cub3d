/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:05:08 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/19 15:47:15 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_screen *screen)
{
	int		cols;
	int		row;
	int		position_src;
	int		position_dst;
	t_image	ceiling;
	double	direction;
	static int		x = 0;

	ceiling = screen->scene.textures[SKY];
	if (x == 0)
		x = screen->scene.textures[SKY].width / 2;
	row = 0;
	direction = screen->player.direction_movement;
	x += direction;
	while (row < ceiling.height)
	{
		cols = 0;
		while (cols < ceiling.width)
		{
			position_dst = (cols) * (
					screen->buffer.bits_per_pixel / 8) + (
					(row) * (
						screen->buffer.size_line));
			position_src = floor(
					(x + cols) / 0.5) * (
					ceiling.bits_per_pixel / 8) + (
					floor(row) * ceiling.size_line);
			copy_byte_to_image(screen->buffer.start_area_ptr + position_dst,
				ceiling.start_area_ptr + position_src);
			cols++;
		}
		row++;
	}
}
