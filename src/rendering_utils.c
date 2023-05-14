/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:28:25 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/14 07:36:09 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray, t_screen *screen)
{
	int		dir;
	double	subseq_angle;
	double	half_fov;

	subseq_angle = screen->raycasting_param.angle_subsequent_rays;
	dir = screen->player.direction;
	half_fov = FOV / 2;
	ray->angle = (double) dir - half_fov + subseq_angle * ray->nbr + 0.00001;
	if (ray->angle > 360)
		ray->angle = ray->angle - 360;
	ray->player = screen->player;
	ray->cosinus = cos(degree_to_radian(ray->angle));
	ray->sinus = sin(degree_to_radian(ray->angle));
	ray->max_step = screen->scene.map.width + screen->scene.map.height;
}
