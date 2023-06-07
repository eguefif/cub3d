/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:33:59 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/04 13:34:58 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_small_walls(t_screen *screen, t_image src, t_object *object);
static void	draw_big_walls(t_screen *screen, t_image src, t_object *object);
static void	calculate_and_copy_small_walls(t_screen *screen,
				t_display_info info, t_object *object);
static void	calculate_and_copy(t_screen *screen,
				t_display_info info, t_object *object);

void	draw_walls(t_screen *screen, t_image src, t_object *object)
{
	object->scale_factor = (double) object->height / src.height;
	if (object->height >= screen->scene.resolution.height)
		draw_big_walls(screen, src, object);
	else
		draw_small_walls(screen, src, object);
}

static void	draw_big_walls(t_screen *screen, t_image src, t_object *object)
{
	t_display_info	info;

	object->subsurface_height = src.height * (
			screen->scene.resolution.height / object->height);
	object->subsurface.y = (double) src.height / 2 - floor(
			object->subsurface_height / 2);
	info.rows = 0;
	info.image = src;
	if (object->type == 'w')
		object->subsurface.x = (int) object->offset * (
				screen->raycasting_param.scale);
	else
		object->subsurface.x = (int) object->offset;
	while (info.rows < screen->scene.resolution.height)
	{
		info.cols = 0;
		while (info.cols < screen->raycasting_param.scale)
		{
			calculate_and_copy(screen, info, object);
			info.cols++;
		}
		info.rows++;
	}
}

static void	calculate_and_copy(t_screen *screen,
				t_display_info info, t_object *object)
{
	int		position_src;
	int		position_dst;

	position_dst = (int)(info.cols + object->buffer_coord.x) * (
			screen->buffer.bits_per_pixel / 8) + (
			((int) object->buffer_coord.y + info.rows) * (
				screen->buffer.size_line));
	position_src = floor(info.cols + object->subsurface.x) * (
			info.image.bits_per_pixel / 8) + (
			floor(info.rows / object->scale_factor + object->subsurface.y) * (
				info.image.size_line));
	copy_byte_to_image(screen->buffer.start_area_ptr + position_dst,
		info.image.start_area_ptr + position_src);
}

static void	draw_small_walls(t_screen *screen, t_image src, t_object *object)
{
	t_display_info	info;

	info.rows = 0;
	object->subsurface.x = object->offset * (
			screen->raycasting_param.scale);
	info.image = src;
	while (info.rows < object->height)
	{
		info.cols = 0;
		while (info.cols < screen->raycasting_param.scale)
		{
			calculate_and_copy_small_walls(screen, info, object);
			info.cols++;
		}
		info.rows++;
	}
}

static void	calculate_and_copy_small_walls(t_screen *screen,
		t_display_info info, t_object *object)
{
	int		position_dst;
	int		position_src;

	position_dst = (int)(info.cols + object->buffer_coord.x) * (
			screen->buffer.bits_per_pixel / 8) + (
			floor(object->buffer_coord.y + info.rows) * (
				screen->buffer.size_line));
	position_src = floor(info.cols + object->subsurface.x) * (
			info.image.bits_per_pixel / 8) + (
			floor(info.rows / object->scale_factor) * info.image.size_line);
	copy_byte_to_image(screen->buffer.start_area_ptr + position_dst,
		info.image.start_area_ptr + position_src);
}
