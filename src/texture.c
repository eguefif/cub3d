/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:49:12 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/16 12:56:43 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

static void	draw_image_on_image(t_screen *screen, t_image src, t_object *wall);
static void	get_texture(t_object *wall);
static void	draw_big_wall(t_screen *screen, t_image src, t_object *wall);
static void	draw_small_wall(t_screen *screen, t_image src, t_object *wall);

void	draw_texture_line(t_screen *screen, t_object *wall)
{
	get_texture(wall);
	draw_image_on_image(screen, screen->scene.textures[wall->texture], wall);
}

static void	draw_image_on_image(t_screen *screen, t_image src, t_object *wall)
{
	wall->scale_factor = (double) wall->height /src.height;
	if (wall->height >= screen->scene.resolution.height)
		draw_big_wall(screen, src, wall);
	else
		draw_small_wall(screen, src, wall);
}

static void	draw_big_wall(t_screen *screen, t_image src, t_object *wall)
{
	int		row;
	int		cols;
	int		position_dst;
	int		position_src;

	wall->subsurface_height= src.height * (
			screen->scene.resolution.height / wall->height);
	wall->subsurface.y= (double) src.height / 2 - floor(wall->subsurface_height / 2);
	wall->subsurface.x= (int) wall->offset;
	row = 0;
	while (row < screen->scene.resolution.height)
	{
		cols = 0;
		while (cols < RESCALE_WIDTH)
		{
			position_dst = (cols + wall->buffer_coord.x) * screen->buffer.bits_per_pixel / 8 + (
					((int) wall->buffer_coord.y + row) * screen->buffer.size_line);
			position_src = (cols + wall->subsurface.x) * src.bits_per_pixel / 8 + (
					floor(row / wall->scale_factor + wall->subsurface.y) * src.size_line);
			copy_byte_to_image(screen->buffer.start_area_ptr + position_dst,
					src.start_area_ptr + position_src);
			cols++;
		}
		row++;
	}
}

static void	draw_small_wall(t_screen *screen, t_image src, t_object *wall)
{
	int		row;
	int		cols;
	int		src_x;
	int		position_dst;
	int		position_src;

	row = 0;
	src_x = (int) wall->offset;
	while (row < wall->height)
	{
		cols = 0;
		while (cols < RESCALE_WIDTH)
		{
			position_dst = (cols + wall->buffer_coord.x) * screen->buffer.bits_per_pixel / 8 + (
					((int) wall->buffer_coord.y + row) * screen->buffer.size_line);
			position_src = (cols + src_x) * src.bits_per_pixel / 8 + (
					floor(row / wall->scale_factor) * src.size_line);
			copy_byte_to_image(screen->buffer.start_area_ptr + position_dst,
					src.start_area_ptr + position_src);
			cols++;
		}
		row++;
	}
}

void	get_texture(t_object *wall)
{
	int		map_x;
	int		map_y;

	map_x = floor(wall->coord.x / SQUARE_SIZE) * SQUARE_SIZE;
	map_y = floor(wall->coord.y / SQUARE_SIZE) * SQUARE_SIZE;
	wall->texture = -1;
	if (wall->coord.x == map_x + SQUARE_SIZE - 0.0001 || map_x == 0)
		wall->texture = WEST;
	else if (wall->coord.x == map_x && map_x != 0)
		wall->texture = EAST;
	else if (wall->coord.y == map_y + SQUARE_SIZE - 0.0001 || map_y == 0)
		wall->texture = NORTH;
	else if (wall->coord.y == map_y && map_y != 0)
		wall->texture = SOUTH;
	if (wall->texture == -1)
		wall->texture = SOUTH;
}
