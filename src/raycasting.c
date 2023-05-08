/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:58:49 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/08 10:06:06 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_first_horizontal_boundary(t_ray *ray);
static void	get_first_vertical_boundary(t_ray *ray);

int	get_distance_to_horizontal_wall(t_map map, t_ray *ray)
{
	int			x_movement;
	t_point		player;

	get_first_horizontal_boundary(ray);
	x_movement = SQUARE_SIZE / tan(degree_to_radian(ray->angle));
	while (!check_for_wall(map, ray->check_position))
	{
		if (ray->angle > 0 && ray->angle < 180)
			ray->check_position.y -= SQUARE_SIZE;
		else if (ray->angle > 180 && ray->angle < 360)
			ray->check_position.y += SQUARE_SIZE;
		if (ray->angle > 0 && ray->angle < 90)
			ray->check_position.x += x_movement;
		else if (ray->angle > 90  && ray->angle < 180)
			ray->check_position.x += x_movement;
		else if (ray->angle > 180  && ray->angle < 270)
			ray->check_position.x -= x_movement;
		else if (ray->angle < 0 || (ray->angle > 270  && ray->angle <= 360))
			ray->check_position.x -= x_movement;
	}
	player.x = ray->player.x;
	player.y = ray->player.y;
	return (calculate_distance(player, ray->check_position));
}

static void	get_first_horizontal_boundary(t_ray *ray)
{
	if (ray->angle > 0 && ray->angle < 180)
		ray->check_position.y = floor(
				floor(ray->player.y / SQUARE_SIZE) * SQUARE_SIZE - 1);
	else if (ray->angle > 180 && ray->angle < 360)
		ray->check_position.y = floor(
				floor(ray->player.y / SQUARE_SIZE) * SQUARE_SIZE + SQUARE_SIZE);
	ray->check_position.x = ray->player.x + (
			ray->player.y - ray->check_position.y) / tan(degree_to_radian(ray->angle));
}

int	get_distance_to_vertical_wall(t_map map, t_ray *ray)
{
	int			y_movement;
	t_point		player;

	get_first_vertical_boundary(ray);
	if (ray->angle == 90 || ray->angle == 270)
		y_movement = SQUARE_SIZE;
	else
		y_movement = SQUARE_SIZE * tan(degree_to_radian(ray->angle));
	while (!check_for_wall(map, ray->check_position))
	{
		if (ray->angle <= 0 ||ray->angle < 90 || ray->angle > 270)
			ray->check_position.x += SQUARE_SIZE;
		else if (ray->angle > 90 && ray->angle < 270)
			ray->check_position.x -= SQUARE_SIZE;
		if (ray->angle >= 0 && ray->angle <= 90)
			ray->check_position.y -= y_movement;
		else if (ray->angle > 90  && ray->angle <= 180)
			ray->check_position.y += y_movement;
		else if (ray->angle > 180  && ray->angle <= 270)
			ray->check_position.y += y_movement;
		else if (ray->angle < 0 || (ray->angle > 270  && ray->angle <= 360))
			ray->check_position.y -= y_movement;
	}
	player.x = ray->player.x;
	player.y = ray->player.y;
	return (calculate_distance(player, ray->check_position));
}

static void	get_first_vertical_boundary(t_ray *ray)
{
	if (ray->angle < 90 || ray->angle > 270)
		ray->check_position.x = floor(
				floor(ray->player.x / SQUARE_SIZE) * SQUARE_SIZE + SQUARE_SIZE);
	else if (ray->angle > 90 && ray->angle < 270)
		ray->check_position.x = floor(
				floor(ray->player.x / SQUARE_SIZE) * SQUARE_SIZE - 1);
	ray->check_position.y = ray->player.y +	(
			ray->player.x - ray->check_position.x) * tan(degree_to_radian(ray->angle));
}
