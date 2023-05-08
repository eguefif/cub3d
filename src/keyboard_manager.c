/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:11:16 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/08 10:22:04 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_direction(int *direction, int step);
static void	move_forward(t_screen *screen);
static void	move_backward(t_screen *screen);

int	keyboard_manager(int key, t_screen *screen)
{
	if (key == ESCAPE)
	{
		terminate_game(screen);
		exit(1);
	}
	else if (key == 119)
		move_forward(screen);
	else if (key == 115)
		move_backward(screen);
	else if (key == 100)
		change_direction(&screen->raycasting_param.player.direction, +10);
	else if (key == 97)
		change_direction(&screen->raycasting_param.player.direction, -10);
	return (1);
}	

static void	change_direction(int *direction, int step)
{
	printf("Current direction %d\n", *direction);
	if (*direction + step > 360)
		*direction = 0 + (step - (360 - *direction));
	else if (*direction + step < 0)
		*direction = 360 + (*direction + step);
	else
		*direction += step;
}

static void	move_forward(t_screen *screen)
{
	double	direction;

	direction = degree_to_radian(screen->raycasting_param.player.direction);
	printf("Forward Direction %f x: %d y: %d\n", direction,
			screen->raycasting_param.player.x,
			screen->raycasting_param.player.y);
	screen->raycasting_param.player.x += cos(direction) * 10;
	screen->raycasting_param.player.y -= sin(direction) * 10;
}

static void	move_backward(t_screen *screen)
{
	double	direction;

	direction = degree_to_radian(screen->raycasting_param.player.direction);
	printf("Backward Direction %f x: %d y: %d\n", direction,
			screen->raycasting_param.player.x,
			screen->raycasting_param.player.y);
	screen->raycasting_param.player.x -= cos(direction) * 10;
	screen->raycasting_param.player.y += sin(direction) * 10;
}
