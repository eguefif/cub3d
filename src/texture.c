/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:49:12 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 12:31:50 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

static void	draw_image_on_image(t_screen_buffer *dst,
		t_image src, t_ray ray, t_raycast_line line);
int		get_texture(void);

void	draw_texture_line(t_screen *screen, t_ray ray, t_raycast_line line)
{
	int		texture;

	texture = get_texture();
	draw_image_on_image(&screen->buffer, screen->scene.textures[texture], ray, line);
}

static void	draw_image_on_image(t_screen_buffer *dst,
		t_image src, t_ray ray, t_raycast_line line)
{
	int		position_dst;
	int		position_src;
	int		row;
	int		cols;
	double	scale_factor;
	int		src_x;

	scale_factor = (double) src.height / line.wall_height;
	row = 0;
	src_x = (int) ray.wall_point.offset;
	while (row < line.wall_height)
	{
		cols = 0;
		while (cols < RESCALE_WIDTH)
		{
			position_dst = (cols + ray.nbr) * dst->bits_per_pixel / 8 + (
					((int) line.y_top + row) * dst->size_line);
			position_src = (cols + src_x) * src.bits_per_pixel / 8 + (
					floor(scale_factor * row) * src.size_line);
			memcpy((dst->start_area_ptr + position_dst), src.start_area_ptr + position_src,
					4 * sizeof(char));
			cols++;
		}
		row++;
	}
}


int	get_texture(void)
{
	return (0);
}
