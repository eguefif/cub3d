/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:19:00 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 08:06:07 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_direction(t_screen *screen);
static void	move(t_screen *screen);
static int	vertical_collision(t_map map, t_point point);
static int	horizontal_collision(t_map map, t_point point);

void	handle_movement(t_screen *screen)
{
	change_direction(screen);
	move(screen);
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
	t_point	futur_position;
	double	direction;
	double	dx;
	double	dy;

	direction = degree_to_radian(screen->player.direction);
	dx = screen->player.coord.x + -cos(direction) * screen->player.movement;
	dy = screen->player.coord.y + -sin(direction) * screen->player.movement;
	futur_position.x = dx;
	futur_position.y = dy;
	if (!vertical_collision(screen->scene.map, futur_position))
	{
		screen->player.coord.x = dx;
	}
	if (!horizontal_collision(screen->scene.map, futur_position))
	{
		screen->player.coord.y = dy;
	}
}

static int	horizontal_collision(t_map map, t_point point)
{
	t_point	top_left;
	t_point	top_right;
	t_point	bot_left;
	t_point	bot_right;

	top_left.x = point.x - PLAYER_SIZE;
	top_left.y = point.y - PLAYER_SIZE;
	top_right.x = point.x + PLAYER_SIZE;
	top_right.y = point.y - PLAYER_SIZE;
	bot_left.x = point.x - PLAYER_SIZE;
	bot_left.y = point.y + PLAYER_SIZE;
	bot_right.x = point.x + PLAYER_SIZE;
	bot_right.y = point.y + PLAYER_SIZE;
	if (check_for_wall(map, top_left) && check_for_wall(map, top_right))
		return (1);
	else if (check_for_wall(map, bot_right) && check_for_wall(map, bot_left))
		return (1);
	return (0);
}

static int	vertical_collision(t_map map, t_point point)
{
	t_point	top_left;
	t_point	top_right;
	t_point	bot_left;
	t_point	bot_right;

	top_left.x = point.x - 4;
	top_left.y = point.y - 4;
	top_right.x = point.x + 4;
	top_right.y = point.y - 4;
	bot_left.x = point.x - 4;
	bot_left.y = point.y + 4;
	bot_right.x = point.x + 4;
	bot_right.y = point.y + 4;
	if (check_for_wall(map, top_right) && check_for_wall(map, bot_right))
		return (1);
	else if (check_for_wall(map, bot_left) && check_for_wall(map, top_left))
		return (1);
	return (0);
}
