/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:27:21 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/08 10:06:42 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_wall_distance(t_screen *screen, t_ray *ray);
static void	correct_fishbowl_dist(t_screen *screen, t_ray *ray);
static void	calculate_vertical_line(t_screen *screen, int distance,
				t_raycast_line *line);
static void	calculate_projection_line(t_screen *screen, t_raycast_line *line,
				int distance);

int	rendering_game(t_screen *screen)
{
	t_raycast_line	line;
	t_ray			ray;

	ray.nbr = 0;
	while (ray.nbr < screen->scene.resolution.width)
	{
		line.x = ray.nbr;
		init_ray(&ray, screen);
		calculate_wall_distance(screen, &ray);
		calculate_vertical_line(screen, ray.wall_distance, &line);
		draw_raycasting_vertical_line(screen, line);
		ray.nbr++;
		//ray.nbr+=50;
	}
	swap_frame_screen(screen);
	return (1);
}

static void	calculate_wall_distance(t_screen *screen, t_ray *ray)
{
	int		distance_to_horizontal_wall;
	int		distance_to_vertical_wall;

	if (ray->angle != 0  && ray->angle != 180 && ray->angle != 360)
		distance_to_horizontal_wall = get_distance_to_horizontal_wall(
					screen->scene.map, ray);
	if (ray->angle != 90 && ray->angle != 270)
		distance_to_vertical_wall = get_distance_to_vertical_wall(
						screen->scene.map, ray);
	ray->wall_distance = min(
			distance_to_horizontal_wall, distance_to_vertical_wall);
	correct_fishbowl_dist(screen, ray);
}

static void	correct_fishbowl_dist(t_screen *screen, t_ray *ray)
{
	double	subsequent_angle;
	double	angle;

	subsequent_angle = screen->raycasting_param.angle_subsequent_rays;
	angle = (double) (-FOV / 2 + (subsequent_angle * ray->nbr));
	angle = (double) degree_to_radian(angle);
	ray->wall_distance = ray->wall_distance * cos(angle);
}

static void	calculate_vertical_line(t_screen *screen, int distance,
		t_raycast_line *line)
{
	line->top_color = screen->scene.ceiling;
	line->mid_color = screen->scene.wall;
	line->bot_color = screen->scene.floor;
	calculate_projection_line(screen, line, distance);
}

static void	calculate_projection_line(t_screen *screen, t_raycast_line *line,
				int distance)
{
	int		projection_line;
	int		projection_var;
	int		center;

	center = screen->scene.resolution.height / 2;
	projection_var = screen->raycasting_param.projection_var;
	if (distance > 0)
		projection_line = projection_var / distance;
	else
		projection_line = 0;
	if (projection_line > screen->scene.resolution.height)
	{
		line->y_top = 0;
		line->y_bot = screen->scene.resolution.height - 1;
	}
	else
	{
		line->y_top = center - projection_line / 2;
		line->y_bot = center + projection_line / 2;
	}
}
