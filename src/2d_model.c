/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_model.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:19:16 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 16:55:06 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_2d_player(t_screen *screen);
static void	draw_tile(int row, int cols, t_screen *screen);
static void	draw_line(t_screen *screen, t_point player, int length);

int	rendering_game_2d(t_screen *screen)
{
	t_ray			ray;

	handle_movement(screen);
	ray.nbr = 0;
	draw_2d_model(screen);
	while (ray.nbr < screen->scene.resolution.width)
	{
		init_ray(&ray, screen);
		calculate_wall_distance(screen, &ray);
		draw_2d_ray(screen, ray);
		ray.nbr ++;
	}
	swap_frame_screen(screen);
	return (0);
}

void	draw_2d_model(t_screen *screen)
{
	int		row;
	int		cols;

	row = 0;
	while (row < screen->scene.map.height)
	{
		cols = 0;
		while (cols < screen->scene.map.width)
		{
			if (screen->scene.map.map[row][cols] == '1')
				draw_tile(row, cols, screen);
			cols++;
		}
		row++;
	}
	draw_2d_player(screen);
}

static void	draw_tile(int row, int cols, t_screen *screen)
{
	int		counter;
	t_point	point;
	int		x;
	int		y;

	counter = 0;
	point.color = screen->scene.floor;
	x = cols * SQUARE_SIZE;
	y = row * SQUARE_SIZE;
	point.y = y;
	while (counter < SQUARE_SIZE)
	{
		point.x = x + counter;
		draw_pixel_on_buffer(screen, point);
		counter++;
	}
	counter = 0;
	while (counter < SQUARE_SIZE)
	{
		point.y = y + counter;
		draw_pixel_on_buffer(screen, point);
		counter++;
	}
	counter = 0;
	x = point.x;
	while (counter < SQUARE_SIZE)
	{
		point.x = x - counter;
		draw_pixel_on_buffer(screen, point);
		counter++;
	}
	counter = 0;
	y = point.y;
	while (counter < SQUARE_SIZE)
	{
		point.y = y - counter;
		draw_pixel_on_buffer(screen, point);
		counter++;
	}
}

void	draw_2d_ray(t_screen *screen, t_ray ray)
{
	double	angle;
	double	dx;
	double	dy;
	int		counter;
	t_point	point;

	angle = degree_to_radian(ray.angle);
	dx = cos(angle);
	dy = sin(angle);
	counter = 0;
	point.x = ray.player.coord.x;
	point.y = ray.player.coord.y;
	point.color = screen->scene.wall;
	while (counter < ray.wall_point.distance)
	{
		point.x += dx;
		point.y += dy;
		draw_pixel_on_buffer(screen, point);
		counter++;
	}
}

static void	draw_2d_player(t_screen *screen)
{
	t_point	point;
	double	counter;
	double	angle;		
	t_point	player;
	double	radius;

	point.color = screen->scene.ceiling;
	player.color = screen->scene.ceiling;
	counter = 0;
	radius = 0;
	while (radius < 4)
	{
		counter = 0;
		while (counter <= 360)
		{
			angle = degree_to_radian(counter);
			point.x = screen->player.coord.x + cos(angle) * radius;
			point.y = screen->player.coord.y + sin(angle) * radius;
			draw_pixel_on_buffer(screen, point);
			counter += 1;
		}
		radius++;
	}
	player = screen->player.coord;
	draw_line(screen, player, 150);
}

static void	draw_line(t_screen *screen, t_point player, int length)
{
	double	angle;
	double	dx;
	double	dy;
	int		counter;
	t_point	point;

	angle = degree_to_radian(screen->player.direction);
	dx = cos(angle);
	dy = sin(angle);
	counter = 0;
	point.x = player.x;
	point.y = player.y;
	while (counter < length)
	{
		point.x += dx;
		point.y += dy;
		draw_pixel_on_buffer(screen, point);
		counter++;
	}
}
