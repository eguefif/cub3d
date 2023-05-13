/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:19:00 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 14:03:07 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_direction(t_screen *screen);
static void	move(t_screen *screen);

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
	if (!check_for_wall(screen->scene.map, dx_check))
	{
		screen->player.coord.x += dx;
	}
	if (!check_for_wall(screen->scene.map, dy_check))
	{
		screen->player.coord.y += dy;
	}
}
