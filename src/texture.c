/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:49:12 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 17:39:02 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

static void	draw_image_on_image(t_screen *screen,
		t_image src, t_ray ray, t_raycast_line line);
int		get_texture(t_ray ray);

void	draw_texture_line(t_screen *screen, t_ray ray, t_raycast_line line)
{
	int		texture;

	texture = get_texture(ray);
	draw_image_on_image(screen, screen->scene.textures[texture], ray, line);
}

static void	draw_image_on_image(t_screen *screen,
		t_image src, t_ray ray, t_raycast_line line)
{
	int		position_dst;
	int		position_src;
	int		row;
	int		cols;
	double	scale_factor;
	int		src_x;
	double	src_y_top;
	double	new_height;

	scale_factor = (double) ray.wall_height /src.height;
	row = 0;
	src_x = (int) ray.wall_point.offset;
	if (ray.wall_height >= screen->scene.resolution.height)
	{
		new_height = src.height * (screen->scene.resolution.height / ray.wall_height);
		src_y_top = (double) src.height / 2 - floor(new_height / 2);
		printf("image height %d y top %f  new height %f image bottom %f \n", 
				src.height, src_y_top, new_height, src.height / scale_factor);
		while (row < screen->scene.resolution.height)
		{
			cols = 0;
			while (cols < RESCALE_WIDTH)
			{
				position_dst = (cols + ray.nbr) * screen->buffer.bits_per_pixel / 8 + (
						((int) line.y_top + row) * screen->buffer.size_line);
				position_src = (cols + src_x) * src.bits_per_pixel / 8 + (
						floor(row / scale_factor + src_y_top) * src.size_line);
				memcpy((screen->buffer.start_area_ptr + position_dst), src.start_area_ptr + position_src,
						4 * sizeof(char));
				cols++;
			}
			row++;
		}
	}
	else
	{
		while (row < ray.wall_height)
		{
			cols = 0;
			while (cols < RESCALE_WIDTH)
			{
				position_dst = (cols + ray.nbr) * screen->buffer.bits_per_pixel / 8 + (
						((int) line.y_top + row) * screen->buffer.size_line);
				position_src = (cols + src_x) * src.bits_per_pixel / 8 + (
						floor(row / scale_factor) * src.size_line);
				memcpy((screen->buffer.start_area_ptr + position_dst), src.start_area_ptr + position_src,
						4 * sizeof(char));
				cols++;
			}
			row++;
		}
	}
}

int	get_texture(t_ray ray)
{
	int		map_x;
	int		map_y;

	map_x = floor(ray.wall_point.coord.x / SQUARE_SIZE) * SQUARE_SIZE;
	map_y = floor(ray.wall_point.coord.y / SQUARE_SIZE) * SQUARE_SIZE;
	if (ray.wall_point.coord.x == map_x)
		return (WEST);
	else if (ray.wall_point.coord.x == map_x + SQUARE_SIZE)
		return (EAST);
	else if (ray.wall_point.coord.y == map_y)
		return (NORTH);
	else if (ray.wall_point.coord.y == map_y + SQUARE_SIZE)
		return (SOUTH);
	return (SOUTH);
}
