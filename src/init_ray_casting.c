/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:03:29 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/16 17:09:24 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycasting(t_screen *screen)
{
	screen->raycasting_param.max_ray_nbr = screen->scene.resolution.width / 2;
	screen->raycasting_param.delta_angle = (double) (
			FOV / screen->raycasting_param.max_ray_nbr);
	screen->raycasting_param.projection_var = SQUARE_SIZE * PROJECTION_PLANE_DST;
	screen->raycasting_param.scale = floor(screen->scene.resolution.width / (
			screen->raycasting_param.max_ray_nbr));
}
