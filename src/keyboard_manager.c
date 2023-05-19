/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:11:16 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/19 15:41:55 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_pressedkey(int key, t_screen *screen)
{
	int		speed;

	speed = SPEED;
	if (key == 65307)
	{
		terminate_game(screen);
		exit(1);
	}
	else if (key == 119)
		screen->player.movement = speed;
	else if (key == 115)
		screen->player.movement = -speed;
	else if (key == 100)
		screen->player.lateral_movement = speed;
	else if (key == 97)
		screen->player.lateral_movement = -speed;
	return (1);
}	

int	handle_releasedkey(int key, t_screen *screen)
{
	if (key == 119)
		screen->player.movement = 0;
	else if (key == 115)
		screen->player.movement = 0;
	else if (key == 100)
		screen->player.lateral_movement = 0;
	else if (key == 97)
		screen->player.lateral_movement = 0;
	return (1);
}	
