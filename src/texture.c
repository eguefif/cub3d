/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:49:12 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 08:27:22 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

void	get_slice(t_image image, t_ray ray, t_image *slice);
int		get_texture(void);

void	draw_texture_line(t_screen *screen, t_ray ray, t_raycast_line line)
{
	int		texture;
	t_image	slice;
	t_image	scaled_slice;
	clock_t	start, end;

	texture = get_texture();
//	start = clock();
	slice = create_image(screen, RESCALE_WIDTH, screen->scene.textures[texture].height);
//	end = clock();
//	printf("Image creating: %f\n", (double) (end - start) / CLOCKS_PER_SEC);
//	start = clock();
	get_slice(screen->scene.textures[texture], ray, &slice);
//	end = clock();
//	printf("Slicing: %f\n", (double) (end - start) / CLOCKS_PER_SEC);
	start = clock();
	scaled_slice = rescale(slice, screen, line.wall_height);
	end = clock();
	printf("Rescaling: %f\n", (double) (end - start) / CLOCKS_PER_SEC);
//	start = clock();
	draw_image_on_image(&screen->buffer, scaled_slice, ray.nbr, line.y_top);
//	end = clock();
//	printf("Drawing: %f\n", (double) (end - start) / CLOCKS_PER_SEC);
//	start = clock();
	mlx_destroy_image(screen->mlx_ptr, scaled_slice.img_ptr);
	mlx_destroy_image(screen->mlx_ptr, slice.img_ptr);
///	end = clock();
//	printf("destroying image: %f\n", (double) (end - start) / CLOCKS_PER_SEC);
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
