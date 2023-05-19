/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:49:12 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/19 10:36:41 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

static void	draw_wall(t_screen *screen, t_image src, t_object *object);
static void	draw_big_object(t_screen *screen, t_image src, t_object *object);
static void	draw_small_object(t_screen *screen, t_image src, t_object *object);
static void	draw_sprite(t_screen *screen, t_image src, t_object *object);

void	draw_objects(t_screen *screen, t_object *object)
{
	if (object->type == 'w')
		draw_wall(screen, screen->scene.textures[object->texture], object);
	else if (object->type == 's')
		draw_sprite(screen, screen->scene.textures[object->texture], object);
}

static void	draw_sprite(t_screen *screen, t_image src, t_object *object)
{
	int		cols;
	int		row;
	int		position_src;
	int		position_dst;

	object->scale_factor = (double) object->height / src.height;
	object->width = object->height * src.ratio;
	row = 0;
	while (row < object->height)
	{
		cols = 0;
		while (cols < object->width)
		{
			position_dst = (cols + object->buffer_coord.x) * (
					screen->buffer.bits_per_pixel / 8) + (
					((int) object->buffer_coord.y + row) * (
						screen->buffer.size_line));
			position_src = floor(
					cols / object->scale_factor) * (
					src.bits_per_pixel / 8) + (
					floor(row / object->scale_factor) * src.size_line);
			copy_byte_to_image(screen->buffer.start_area_ptr + position_dst,
				src.start_area_ptr + position_src);
			cols++;
		}
		row++;
	}
}

static void	draw_wall(t_screen *screen, t_image src, t_object *object)
{
	object->scale_factor = (double) object->height / src.height;
	if (object->height >= screen->scene.resolution.height)
		draw_big_object(screen, src, object);
	else
		draw_small_object(screen, src, object);
}

static void	draw_big_object(t_screen *screen, t_image src, t_object *object)
{
	int		row;
	int		cols;
	int		position_dst;
	int		position_src;

	object->subsurface_height = src.height * (
			screen->scene.resolution.height / object->height);
	object->subsurface.y = (double) src.height / 2 - floor(
			object->subsurface_height / 2);
	row = 0;
	if (object->type == 'w')
		object->subsurface.x = (int) object->offset * (
				screen->raycasting_param.scale);
	else
		object->subsurface.x = (int) object->offset;
	while (row < screen->scene.resolution.height)
	{
		cols = 0;
		while (cols < screen->raycasting_param.scale)
		{
			position_dst = (cols + object->buffer_coord.x) * (
					screen->buffer.bits_per_pixel / 8) + (
					((int) object->buffer_coord.y + row) * (
						screen->buffer.size_line));
			position_src = floor(cols + object->subsurface.x) * (
					src.bits_per_pixel / 8) + (
					floor(row / object->scale_factor + object->subsurface.y) * (
						src.size_line));
			copy_byte_to_image(screen->buffer.start_area_ptr + position_dst,
				src.start_area_ptr + position_src);
			cols++;
		}
		row++;
	}
}

static void	draw_small_object(t_screen *screen, t_image src, t_object *object)
{
	int		row;
	int		cols;
	int		position_dst;
	int		position_src;

	row = 0;
	object->subsurface.x = (int) object->offset * (
			screen->raycasting_param.scale);
	while (row < object->height)
	{
		cols = 0;
		while (cols < screen->raycasting_param.scale)
		{
			position_dst = (cols + object->buffer_coord.x) * (
					screen->buffer.bits_per_pixel / 8) + (
					((int) object->buffer_coord.y + row) * (
						screen->buffer.size_line));
			position_src = floor(cols + object->subsurface.x) * (
					src.bits_per_pixel / 8) + (
					floor(row / object->scale_factor) * src.size_line);
			copy_byte_to_image(screen->buffer.start_area_ptr + position_dst,
				src.start_area_ptr + position_src);
			cols++;
		}
		row++;
	}
}
