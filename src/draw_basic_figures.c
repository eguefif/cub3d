/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_basic_figures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:57:50 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/06 19:20:57 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_pixel_on_buffer(t_screen *screen, t_point point);
static void	draw_top_part(t_screen *screen, t_raycasting_vertical_line line);
static void	draw_mid_part(t_screen *screen, t_raycasting_vertical_line line);
static void	draw_bot_part(t_screen *screen, t_raycasting_vertical_line line);

void	draw_raycasting_vertical_line(t_screen *screen,
		t_raycasting_vertical_line line)
{
	draw_top_part(screen, line);
	draw_mid_part(screen, line);
	draw_bot_part(screen, line);
}

static void	draw_top_part(t_screen *screen, t_raycasting_vertical_line line)
{
	t_point	point;
	int		counter;

	point.x = line.x;
	point.color = line.top_color;
	counter = 0;
	while (counter < line.y_top)
	{
		point.y = 0 + counter;
		draw_pixel_on_buffer(screen, point);
		counter++;
	}
}

static void	draw_mid_part(t_screen *screen, t_raycasting_vertical_line line)
{
	t_point	point;
	int		counter;
	int		y_limit;

	counter = 0;
	point.x = line.x;
	point.color = line.mid_color;
	y_limit = line.y_bot - line.y_top;
	while (counter < y_limit)
	{
		point.y = line.y_top + counter;
		draw_pixel_on_buffer(screen, point);
		counter++;
	}
}

static void	draw_bot_part(t_screen *screen, t_raycasting_vertical_line line)
{
	t_point	point;
	int		counter;
	int		y_limit;

	counter = 0;
	point.x = line.x;
	point.color = line.bot_color;
	y_limit = screen->scene.resolution.height - line.y_bot;
	while (counter < y_limit)
	{
		point.y = line.y_bot + counter;
		draw_pixel_on_buffer(screen, point);
		counter++;
	}
}

void	draw_pixel_on_buffer(t_screen *screen, t_point point)
{
	int		position;
	int		y;
	int		x;
	char	*dst;

	y = screen->buffer.size_line * point.y;
	x = point.x * screen->buffer.bits_per_pixel / 8;
	position = x + y;
	dst = screen->buffer.start_area_ptr + position;
	*(unsigned int *)dst = point.color.rgb;
}
