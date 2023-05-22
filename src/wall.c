/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 07:48:27 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/22 09:21:18 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	define_buffer_coordinate(t_screen *screen, t_object *wall);
static void	calculate_projection(t_screen *screen, t_object *wall);
static void	get_texture(t_object *wall);

t_object	*calculate_wall_projection(t_screen *screen, t_ray *ray)
{
	t_object	*wall;

	wall = (t_object *) malloc(sizeof(t_object));
	wall->type = 'w';
	get_dist_to_vertical_wall(screen->scene.map, ray);
	get_dist_to_horizontal_wall(screen->scene.map, ray);
	get_shorter_distance(&ray->vertical_check, &ray->horizontal_check, wall);
	wall->ray_nbr = ray->nbr;
	wall->ray_angle = ray->angle;
	correct_fishbowl_effect(screen, wall);
	calculate_projection(screen, wall);
	define_buffer_coordinate(screen, wall);
	get_texture(wall);
	return (wall);
}

void	correct_fishbowl_effect(t_screen *screen, t_object *wall)
{
	double	delta_angle;
	double	angle;

	delta_angle = screen->raycasting_param.delta_angle;
	angle = (double)(-FOV / 2 + (delta_angle * wall->ray_nbr));
	angle = (double) degree_to_radian(angle);
	wall->distance = wall->distance * cos(angle);
}

static void	calculate_projection(t_screen *screen, t_object *wall)
{
	wall->height = screen->raycasting_param.projection_var / wall->distance;
}

static void	define_buffer_coordinate(t_screen *screen, t_object *wall)
{
	int		center;

	center = screen->scene.resolution.height / 2;
	wall->buffer_coord.x = wall->ray_nbr * screen->raycasting_param.scale;
	if (wall->height >= screen->scene.resolution.height)
		wall->buffer_coord.y = 0;
	else
		wall->buffer_coord.y = center - wall->height / 2;
}

void	get_texture(t_object *wall)
{
	double	map_x;
	double	map_y;

	map_x = floor(wall->coord.x / SQUARE_SIZE) * SQUARE_SIZE;
	map_y = floor(wall->coord.y / SQUARE_SIZE) * SQUARE_SIZE;
	wall->texture = -1;
	if (wall->coord.x == map_x && map_x != 0)
		wall->texture = EAST;
	else if ((ceil(wall->coord.y) == ceil(map_y + SQUARE_SIZE - 0.0001)) || map_y == 0)
		wall->texture = NORTH;
	else if (wall->coord.y == map_y && map_y != 0)
		wall->texture = SOUTH;
	else if ((ceil(wall->coord.x) == ceil(map_x + SQUARE_SIZE - 0.0001)) || map_x == 0)
		wall->texture = WEST;
}
