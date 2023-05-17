/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_horizontal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:58:49 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/16 17:19:29 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_point	find_first_horizontal(t_map, t_ray *ray);
static void		get_horizontal_offset_texture(t_ray *ray);

void	get_dist_to_horizontal_wall(t_map map, t_ray *ray)
{
	int		counter;

	ray->horizontal_check.coord = find_first_horizontal(map, ray);
	counter = 0;
	while (counter < ray->max_step)
	{
		if (check_for_wall(map, ray->horizontal_check.coord))
			break ;
		ray->horizontal_check.coord.x += ray->dx;
		ray->horizontal_check.coord.y += ray->dy;
		ray->horizontal_check.distance += ray->d_depth;
		counter++;
	}
	ray->horizontal_check.distance = fabs(ray->horizontal_check.distance);
	get_horizontal_offset_texture(ray);
}

static t_point	find_first_horizontal(t_map, t_ray *ray)
{
	t_point		check;
	t_point		player_map_pos;

	player_map_pos.x = floor(ray->player.coord.x / SQUARE_SIZE) * SQUARE_SIZE;
	player_map_pos.y = floor(ray->player.coord.y / SQUARE_SIZE) * SQUARE_SIZE;
	if (ray->sinus > 0)
	{
		ray->dy = SQUARE_SIZE;
		check.y = player_map_pos.y + SQUARE_SIZE;
	}
	else
	{
		ray->dy = -SQUARE_SIZE;
		check.y = player_map_pos.y - 0.0001;
	}
	ray->horizontal_check.distance = (check.y - ray->player.coord.y) / ray->sinus;
	check.x = ray->player.coord.x + ray->horizontal_check.distance * ray->cosinus;
	ray->d_depth = ray->dy / ray->sinus;
	ray->dx = ray->d_depth * ray->cosinus;
	return (check);
}

static void	get_horizontal_offset_texture(t_ray *ray)
{
	if (ray->sinus > 0)
		ray->horizontal_check.offset = SQUARE_SIZE - ((int)
							ray->horizontal_check.coord.x % SQUARE_SIZE);
	else
		ray->horizontal_check.offset = (int) ray->horizontal_check.coord.x % SQUARE_SIZE;
	printf("fct: %f\n", ray->horizontal_check.offset);
}
