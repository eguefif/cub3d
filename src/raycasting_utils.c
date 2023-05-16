/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:15:55 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/15 20:58:47 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_point_in_map(t_map map, int x, int y);

int	check_for_wall(t_map map, t_point point)
{
	int		x;
	int		y;

	x = (int) floor(point.x / SQUARE_SIZE);
	y = (int) floor(point.y / SQUARE_SIZE);
	if (is_point_in_map(map, x, y))
	{
		if (map.map[y][x] == '1')
		{
			return (1);
		}
	}
	else
	{
		return (1);
	}
	return (0);
}

static int	is_point_in_map(t_map map, int x, int y)
{
	if (x < 0 || x >= map.width)
		return (0);
	else if (y < 0 || y >= map.height)
		return (0);
	return (1);
}

int	calculate_distance(t_point player, t_point wall)
{
	int		distance;

	distance = sqrt(pow(player.x - wall.x, 2) + pow(player.y - wall.y, 2));
	return (distance);
}

double	degree_to_radian(double angle)
{
	return ((double) angle * 2 * M_PI / 360);
}

void	get_shorter_distance(t_object *distance1, t_object *distance2, t_object *wall)
{
	if (distance1->distance <= distance2->distance && distance1->distance > 0)
	{
		wall->coord = distance1->coord;
		wall->distance = distance1->distance;
		wall->offset = distance1->offset;
	}
	else if (distance2->distance > 0)
	{
		wall->coord = distance2->coord;
		wall->distance = distance2->distance;
		wall->offset = distance2->offset;
	}
}

void	init_ray(t_ray *ray, t_screen *screen)
{
	int		dir;
	double	subseq_angle;
	double	half_fov;

	subseq_angle = screen->raycasting_param.angle_subsequent_rays;
	dir = screen->player.direction;
	half_fov = FOV / 2;
	ray->angle = (double) dir - half_fov + subseq_angle * ray->nbr;
	if (ray->angle > 360)
		ray->angle = ray->angle - 360;
	ray->player = screen->player;
	ray->cosinus = cos(degree_to_radian(ray->angle));
	ray->sinus = sin(degree_to_radian(ray->angle));
	ray->max_step = screen->scene.map.width + screen->scene.map.height;
}
