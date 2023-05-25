/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:39:10 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/24 20:47:54 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_manager(int button, int x, int y, t_screen *screen)
{
	static int	x_pos = 0;

	if (x_pos == 0)
		x_pos = x;
	else
		printf("Button %d, %d %d, width %d\n",
				button, x, y, screen->scene.resolution.width);
	return (0);
}
