/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:49:12 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 10:54:13 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

void	get_slice(t_image image, t_ray ray, t_image *slice);
int		get_texture(void);

void	draw_texture_line(t_screen *screen, t_ray ray, t_raycast_line line)
{
	int		texture;

	texture = get_texture();
	draw_image_on_image(&screen->buffer, screen->scene.textures[texture], ray, line);
}

int	get_texture(void)
{
	return (0);
}

void	get_slice(t_image image, t_ray ray, t_image *slice)
{
	int		row;
	int		cols;
	int		slice_position;
	int		image_position;

	row = 0;
	while (row < image.height)
	{
		cols = 0;
		while (cols < slice->width)
		{
			slice_position = cols * slice->bits_per_pixel / 8 + row * slice->size_line;
			image_position = (int) (cols + ray.wall_point.offset) * (image.bits_per_pixel / 8) + (
					row * image.size_line);
			memcpy((slice->start_area_ptr + slice_position), image.start_area_ptr + image_position, 4 * sizeof(char));
			cols++;
		}
		row++;
	}
}
