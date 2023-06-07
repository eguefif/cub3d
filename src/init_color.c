/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:46:47 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/04 13:47:01 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_color(t_screen *screen)
{
	screen->scene.floor.rgb = get_color(screen, screen->scene.floor);
	screen->scene.ceiling.rgb = get_color(screen, screen->scene.ceiling);
	screen->scene.wall.red = 255;
	screen->scene.wall.green = 255;
	screen->scene.wall.blue = 255;
	screen->scene.wall.rgb = get_color(screen, screen->scene.wall);
}

int	get_color(t_screen *screen, t_color color)
{
	int		rgb;

	rgb = color.blue + color.green * 256 + color.red * 65536;
	return (mlx_get_color_value(screen->mlx_ptr, rgb));
}
