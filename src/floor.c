/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:12:21 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/16 07:58:50 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(t_screen *screen)
{
	int		width;
	int		height;
	t_point	location;

	location.color = screen->scene.floor;
	width = screen->scene.resolution.width;
	height = screen->scene.resolution.height / 2 - 1;
	location.x = 0;
	location.y = screen->scene.resolution.height / 2 + 1;
	draw_rectangle(screen, width, height, location);
}
