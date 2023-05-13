/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_treatement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:26:25 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 12:31:54 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	create_image(t_screen *screen, int width, int height)
{
	t_image	image;

	image.img_ptr = mlx_new_image(screen->mlx_ptr, width, height);
	image.width = width;
	image.height = height;
	image.start_area_ptr = mlx_get_data_addr(
			image.img_ptr,
			&image.bits_per_pixel,
			&image.size_line,
			&image.endian);
	return (image);
}
