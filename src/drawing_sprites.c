/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:55:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/04 15:17:51 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_in_buffer(t_display_info position_dst,
				t_screen_buffer buffer, t_object *object);
static void	calculate_and_copy_pixel(t_screen *screen,
				t_display_info info, t_object *object);

void	draw_sprites(t_screen *screen, t_image *src, t_object *object)
{
	t_display_info	info;
	int				ret_val;

	object->scale_factor = (double) object->height / src->height;
	info.rows = 0;
	info.image = *src;
	while (info.rows < object->height)
	{
		info.cols = 0;
		while (info.cols < object->width)
		{
			ret_val = is_in_buffer(info, screen->buffer, object);
			if (ret_val == 1)
				calculate_and_copy_pixel(screen, info, object);
			else if (ret_val == 0)
				break ;
			info.cols++;
		}
		info.rows++;
	}
}

static void	calculate_and_copy_pixel(t_screen *screen,
		t_display_info info, t_object *object)
{
	int		position_dst;
	int		position_src;

	position_dst = (info.cols + (int)object->buffer_coord.x) * (
			screen->buffer.bits_per_pixel / 8) + (
			((int) object->buffer_coord.y + info.rows) * (
				screen->buffer.size_line));
	position_src = (int) floor(
			info.cols / object->scale_factor) * (
			info.image.bits_per_pixel / 8) + (
			floor(info.rows / object->scale_factor) * info.image.size_line);
	copy_byte_to_image(screen->buffer.start_area_ptr + position_dst,
		info.image.start_area_ptr + position_src);
}

static int	is_in_buffer(t_display_info info,
		t_screen_buffer buffer, t_object *object)
{
	int		buffer_x;

	buffer_x = (info.cols + (int)object->buffer_coord.x) * (
			buffer.bits_per_pixel / 8);
	if (buffer_x >= buffer.size_line)
		return (0);
	else if (buffer_x <= 0)
		return (2);
	return (1);
}
