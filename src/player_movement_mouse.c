/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_mouse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:38:51 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/04 13:43:53 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_mouse_position(int x, int y, t_screen *screen);
static int	get_rotation_speed(int acceleration);

void	mouse_movement(t_screen *screen)
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
	if (acceleration < 10 && acceleration > -10)
		return (speed);
	else if ((acceleration >= 10 && acceleration <= 20) || (
			acceleration <= -10 && acceleration >= -20))
		return (speed + 3);
	else if ((acceleration > 20 && acceleration <= 30) || (
			acceleration < -20 && acceleration >= -30))
		return (speed + 4);
	else if (acceleration > 30 && acceleration < -30)
		return (speed + 5);
	return (0);
}
