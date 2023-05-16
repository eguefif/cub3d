/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 07:48:27 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/15 20:52:20 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	correct_fishbowl_effect(t_screen *screen, t_object *wall);
static void	define_buffer_coordinate(t_screen *screen, t_object *wall);
static void	calculate_projection(t_screen *screen, t_object *wall);

t_object	*calculate_wall_projection(t_screen *screen, t_ray *ray)
{
	t_object	*wall;

	wall = (t_object *) malloc(sizeof(t_object));
	get_dist_to_vertical_wall(screen->scene.map, ray);
	get_dist_to_horizontal_wall(screen->scene.map, ray);
	get_shorter_distance(&ray->vertical_check, &ray->horizontal_check, wall);
	wall->ray_nbr = ray->nbr;
	correct_fishbowl_effect(screen, wall);
	calculate_projection(screen, wall);
	define_buffer_coordinate(screen, wall);
	return (wall);
}

static void	correct_fishbowl_effect(t_screen *screen, t_object *wall)
{
	double	delta_angle;
	double	angle;

	delta_angle = screen->raycasting_param.angle_subsequent_rays;
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
	wall->buffer_coord.x = wall->ray_nbr;
	if (wall->height >= screen->scene.resolution.height)
		wall->buffer_coord.y = 0;
	else
		wall->buffer_coord.y = center - wall->height / 2;
}
