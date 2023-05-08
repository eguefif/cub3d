/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:46:27 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/06 19:47:34 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap_frame_screen(t_screen *screen)
{
	mlx_put_image_to_window(screen->mlx_ptr,
		screen->window,
		screen->buffer.img_ptr,
		0,
		0);
	mlx_destroy_image(screen->mlx_ptr,
		screen->buffer.img_ptr);
	init_screen_buffer(screen);
}
