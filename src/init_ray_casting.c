/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:03:29 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/07 10:47:15 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycasting(t_screen *screen)
{
	int		width;
	int		height;
	int		fov;
	int		dist;

	screen->raycasting_param.field_of_view = FOV;
	width = screen->scene.resolution.width;
	screen->raycasting_param.projection_plane.width = width;
	height = screen->scene.resolution.height;
	screen->raycasting_param.projection_plane.height = height;
	screen->raycasting_param.projection_plane.player_plane_distance = 277;
	fov = screen->raycasting_param.field_of_view;
	screen->raycasting_param.angle_subsequent_rays = (double) fov / width;
	dist = screen->raycasting_param.projection_plane.player_plane_distance;
	screen->raycasting_param.projection_var = SQUARE_SIZE * dist;
}
