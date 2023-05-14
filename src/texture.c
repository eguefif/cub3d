/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:49:12 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 18:02:24 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

static void	draw_image_on_image(t_screen *screen,
		t_image src, t_ray ray, t_raycast_line line);
int		get_texture(t_ray ray);
static void	draw_big_wall(t_screen *screen, t_image src, t_ray ray, double scale_factor, int buffer_y);
static void	draw_small_wall(t_screen *screen, t_image src, t_ray ray, double scale_factor, int buffer_y);

void	draw_texture_line(t_screen *screen, t_ray ray, t_raycast_line line)
{
	int		texture;

	texture = get_texture(ray);
	draw_image_on_image(screen, screen->scene.textures[texture], ray, line);
}

static void	draw_image_on_image(t_screen *screen,
		t_image src, t_ray ray, t_raycast_line line)
{
	double	scale_factor;

	scale_factor = (double) ray.wall_height /src.height;
	if (ray.wall_height >= screen->scene.resolution.height)
		draw_big_wall(screen, src, ray, scale_factor, line.y_top);
	else
		draw_small_wall(screen, src, ray, scale_factor, line.y_top);
}

static void	draw_big_wall(t_screen *screen, t_image src, t_ray ray, double scale_factor, int buffer_y)
{
	t_texture_param	param;
	int		row;
	int		cols;

	param.new_height = src.height * (
			screen->scene.resolution.height / ray.wall_height);
	param.src_y = (double) src.height / 2 - floor(param.new_height / 2);
	param.src_x = (int) ray.wall_point.offset;
	row = 0;
	while (row < screen->scene.resolution.height)
	{
		cols = 0;
		while (cols < RESCALE_WIDTH)
		{
			param.position_dst = (cols + ray.nbr) * screen->buffer.bits_per_pixel / 8 + (
					((int) buffer_y+ row) * screen->buffer.size_line);
			param.position_src = (cols + param.src_x) * src.bits_per_pixel / 8 + (
					floor(row / scale_factor + param.src_y) * src.size_line);
			memcpy((screen->buffer.start_area_ptr + param.position_dst),
					src.start_area_ptr + param.position_src,
					4 * sizeof(char));
			cols++;
		}
		row++;
	}
}

static void	draw_small_wall(t_screen *screen, t_image src, t_ray ray, double scale_factor, int buffer_y)
{
	int		row;
	int		cols;
	int		src_x;
	int		position_dst;
	int		position_src;

	row = 0;
	src_x = (int) ray.wall_point.offset;
	while (row < ray.wall_height)
	{
		cols = 0;
		while (cols < RESCALE_WIDTH)
		{
			position_dst = (cols + ray.nbr) * screen->buffer.bits_per_pixel / 8 + (
					((int) buffer_y + row) * screen->buffer.size_line);
			position_src = (cols + src_x) * src.bits_per_pixel / 8 + (
					floor(row / scale_factor) * src.size_line);
			memcpy((screen->buffer.start_area_ptr + position_dst), src.start_area_ptr + position_src,
					4 * sizeof(char));
			cols++;
		}
		row++;
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
	else if (ceil(ray.wall_point.coord.x) == map_x + SQUARE_SIZE)
		return (EAST);
	else if (ray.wall_point.coord.y == map_y)
		return (NORTH);
	else if (ray.wall_point.coord.y == map_y + SQUARE_SIZE)
		return (SOUTH);
	return (SOUTH);
}
