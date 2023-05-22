/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:19:00 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/22 11:05:56 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_direction(t_screen *screen);
static void	move(t_screen *screen);
static void	mouse_movement(t_screen *screen);
static int	get_rotation_speed(int acceleration);
static void	check_mouse_position(int x, int y, t_screen *screen);
static void	move_lateral(t_screen *screen);

void	handle_movement(t_screen *screen)
{
	mouse_movement(screen);
	change_direction(screen);
	move(screen);
	move_lateral(screen);
}

static void	mouse_movement(t_screen *screen)
{
	int		y;
	int		x;
	int		acceleration;
	int		speed;

	mlx_mouse_get_pos(screen->mlx_ptr, screen->window, &x, &y);
	check_mouse_position(x, y, screen);
	if (screen->mouse.x == screen->scene.resolution.width / 2)
		screen->mouse.x = x;
	else
	{
		acceleration = x - screen->mouse.x;
		speed = get_rotation_speed(acceleration);
		if (acceleration > 0)
			screen->player.direction_movement = speed;
		else if (acceleration < 0)
			screen->player.direction_movement = -speed;
		else if (acceleration == 0)
			screen->player.direction_movement = 0;
	}
	screen->mouse.x = x;
}

static void	check_mouse_position(int x, int y, t_screen *screen)
{
	if (x >= screen->scene.resolution.width - 100 || x <= 0)
		init_mouse(screen);
	else if (y > screen->scene.resolution.height - 100 || y <= 0)
		init_mouse(screen);
}

static int	get_rotation_speed(int acceleration)
{
	int		speed;

	speed = ROT_SPEED;
	if (acceleration < 10 && acceleration > - 10)
		return (speed);
	else if ((acceleration >= 10 && acceleration <= 20) || (acceleration <= -10 && acceleration >= -20))
		return (speed + 3);
	else if ((acceleration > 20 && acceleration <= 30) || (acceleration < -20 && acceleration >= -30))
		return (speed + 4);
	else if (acceleration > 30 &&  acceleration <  -30)
		return (speed + 5);
	return (0);
}

static void	change_direction(t_screen *screen)
{
	t_player	player;

	player = screen->player;
	if (player.direction_movement != 0)
	{
		if (screen->player.direction + player.direction_movement > 360)
			screen->player.direction = 0 + (
					player.direction_movement - (
						360 - screen->player.direction));
		else if (screen->player.direction + player.direction_movement < 0)
			screen->player.direction = 360 + (
					screen->player.direction + player.direction_movement);
		else
			screen->player.direction += player.direction_movement;
	}
}

static void	move(t_screen *screen)
{
	t_point	dx_check;
	t_point	dy_check;
	double	direction;
	double	dx;
	double	dy;

	direction = degree_to_radian(screen->player.direction);
	dx = cos(direction) * screen->player.movement;
	dy = sin(direction) * screen->player.movement;
	dx_check.x = screen->player.coord.x + dx * PLAYER_SIZE;
	dx_check.y = screen->player.coord.y;
	dy_check.x = screen->player.coord.x;
	dy_check.y = screen->player.coord.y + dy * PLAYER_SIZE;
	if (!check_for_collision(screen->scene.map, dx_check))
	{
		screen->player.coord.x += dx;
	}
	if (!check_for_collision(screen->scene.map, dy_check))
	{
		screen->player.coord.y += dy;
	}
}

static void	move_lateral(t_screen *screen)
{
	t_point	dx_check;
	t_point	dy_check;
	double	direction;
	double	dx;
	double	dy;

	direction = screen->player.direction;
	if (screen->player.lateral_movement < 0)
		direction = degree_to_radian(direction + 90);
	else if (screen->player.lateral_movement > 0)
		direction = degree_to_radian(direction - 270);
	dx = cos(direction) * screen->player.lateral_movement;
	dy = sin(direction) * screen->player.lateral_movement;
	dx_check.x = screen->player.coord.x + dx * PLAYER_SIZE;
	dx_check.y = screen->player.coord.y;
	dy_check.x = screen->player.coord.x;
	dy_check.y = screen->player.coord.y + dy * PLAYER_SIZE;
	if (!check_for_collision(screen->scene.map, dx_check))
	{
		screen->player.coord.x += dx;
	}
	if (!check_for_collision(screen->scene.map, dy_check))
	{
		screen->player.coord.y += dy;
	}
}
