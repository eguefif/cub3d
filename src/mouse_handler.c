/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:39:10 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/19 14:43:27 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_manager(int button, int x, int y, t_screen *screen)
{
	static int	x_pos = 0;

	if (x_pos == 0)
		x_pos = x;
	else
		printf("%d button %d, (%d, %d)\n", screen->scene.resolution.width, button, x, y);
	return (0);
}
