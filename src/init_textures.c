/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:19:10 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/12 17:17:00 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_texture(void *mlx_ptr, t_image *image);

void	init_textures(t_screen *screen)
{
	int		counter;

	counter = 0;
	while (counter < NBR_TEXTURES)
	{
		init_texture(screen->mlx_ptr, &screen->scene.textures[counter]);
		counter++;
	}
}

static void	init_texture(void *mlx_ptr, t_image *image)
{
	image->img_ptr = mlx_xpm_file_to_image(mlx_ptr, image->path,
			&image->width, &image->height);
	image->start_area_ptr = mlx_get_data_addr(image->img_ptr,
			&image->bits_per_pixel, &image->size_line, &image->endian);
}
