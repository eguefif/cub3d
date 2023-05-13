/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 07:58:25 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/12 17:37:58 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	correct_fishbowl_dist(t_screen *screen, t_ray *ray);
static void	calculate_vertical_line(t_screen *screen, int distance,
				t_raycast_line *line);
static void	calculate_projection_line(t_screen *screen, t_raycast_line *line,
				int distance);

int	rendering_game(t_screen *screen)
{
	t_raycast_line	line;
	t_ray			ray;
	clock_t			start, end;

	ray.nbr = 0;
	handle_movement(screen);
	while (ray.nbr < screen->scene.resolution.width)
	{
		line.x = ray.nbr;
		init_ray(&ray, screen);
		calculate_wall_distance(screen, &ray);
		correct_fishbowl_dist(screen, &ray);
		calculate_vertical_line(screen, ray.wall_point.distance, &line);
		draw_raycasting_vertical_line(screen, line);
		start = clock();
		draw_texture_line(screen, ray, line);
		end = clock();
		printf("--------NEW casting one ray: %f\n", (double) (end - start) / CLOCKS_PER_SEC);
		ray.nbr += RESCALE_WIDTH;
	}
	//check_time(screen);
	swap_frame_screen(screen);
	return (0);
}

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

static void	correct_fishbowl_dist(t_screen *screen, t_ray *ray)
{
	double	subsequent_angle;
	double	angle;

	subsequent_angle = screen->raycasting_param.angle_subsequent_rays;
	angle = (double)(-FOV / 2 + (subsequent_angle * ray->nbr));
	angle = (double) degree_to_radian(angle);
	ray->wall_point.distance = ray->wall_point.distance * cos(angle);
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
	if (projection_line >= screen->scene.resolution.height)
	{
		line->y_top = 0;
		line->y_bot = screen->scene.resolution.height - 1;
		line->wall_height = screen->scene.resolution.height;
	}
	else
	{
		line->y_top = center - projection_line / 2;
		line->y_bot = center + projection_line / 2;
		line->wall_height = projection_line;
	}
}
