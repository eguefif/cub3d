/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:39:00 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/07 20:14:18 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_point_in_map(t_map map, int x, int y);

int	check_for_wall(t_map map, t_point point)
{
	int		x;
	int		y;

	x = floor(point.x / SQUARE_SIZE);
	y = floor(point.y / SQUARE_SIZE);
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
