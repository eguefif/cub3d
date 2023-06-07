/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:44:35 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/04 14:27:11 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calculate_distance(t_point player, t_point wall)
{
	int		distance;

	distance = sqrt(pow(player.x - wall.x, 2) + pow(player.y - wall.y, 2));
	return (distance);
}

double	degree_to_radian(double angle)
{
	return ((double) angle * M_PI / 180);
}
