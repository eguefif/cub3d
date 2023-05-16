/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:05:08 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/16 07:43:25 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_screen *screen)
{
	int		width;
	int		height;
	t_point	location;

	location.color = screen->scene.ceiling;
	width = screen->scene.resolution.width;
	height = screen->scene.resolution.height / 2;
	location.x = 0;
	location.y = 0;
	draw_rectangle(screen, width, height, location);
}
