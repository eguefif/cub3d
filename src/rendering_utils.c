/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:28:25 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/08 08:22:57 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray, t_screen *screen)
{
	int		direction;
	double	subsequent_angle;

	subsequent_angle = screen->raycasting_param.angle_subsequent_rays;
	direction = screen->raycasting_param.player.direction;
	ray->angle = (double) direction - FOV / 2 + subsequent_angle * ray->nbr;
	if (ray->angle > 360)
		ray->angle = ray->angle - 360;
	ray->player = screen->raycasting_param.player;
}

int	min(int a, int b)
{
	if (a <= b && a >= 0)
		return (a);
	else if (b > 0)
		return (b);
	return (0);
}
