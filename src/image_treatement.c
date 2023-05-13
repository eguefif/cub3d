/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_treatement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:26:25 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 11:42:50 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_bytes_and_scale(t_image image,
				t_image *scaled_image, int cols, int row, double scale_factor);

t_image	rescale(t_image image, t_screen *screen, int scale)
{
	double	scale_factor;
	int		row;
	int		cols;
	t_image	scaled_image;
	clock_t	start, end;

	scale_factor = (double) image.height / scale;
	scaled_image.width = image.width;
	scaled_image.height = scale;
	start = clock();
	scaled_image.img_ptr = mlx_new_image(screen->mlx_ptr,
			scaled_image.width, scaled_image.height);
	end = clock();
	printf("Prep rescaling: %f\n", (double) (end - start) / CLOCKS_PER_SEC);
	scaled_image.start_area_ptr = mlx_get_data_addr(scaled_image.img_ptr,
			&scaled_image.bits_per_pixel, &scaled_image.size_line, &scaled_image.endian);
	row = 0;

	start = clock();
	while (row < scaled_image.height)
	{
		cols = 0;
		while (cols < image.width)
		{
			copy_bytes_and_scale(image, &scaled_image, cols, row, scale_factor);
			cols++;
		}
		row++;
	}
	end = clock();
	printf("end rescaling: %f\n", (double) (end - start) / CLOCKS_PER_SEC);
	return (scaled_image);
}

static void	copy_bytes_and_scale(t_image image,
		t_image *scaled_image, int cols, int row, double scale_factor)
{
	int		img_position;
	int		scaled_img_position;
	int		bpp;

	bpp = image.bits_per_pixel;
	img_position = (int) floor(cols * scale_factor) * bpp / 8 + floor(
			row * scale_factor) * scaled_image->size_line;
	scaled_img_position = (int) cols * bpp / 8 + row * image.size_line;
	memcpy(scaled_image->start_area_ptr + scaled_img_position,
			image.start_area_ptr + img_position, 4 * sizeof(char));
}

void	draw_image_on_image(t_screen_buffer *dst, t_image src, t_ray ray, t_raycast_line line)
{
	int		position_dst;
	int		position_src;
	int		row;
	int		cols;
	double	scale_factor;
	int		src_x;

	scale_factor = (double) src.height / line.wall_height;
	row = 0;
	src_x = (int) ray.wall_point.offset;
	while (row < line.wall_height)
	{
		cols = 0;
		while (cols < RESCALE_WIDTH)
		{
			position_dst = (cols + ray.nbr) * dst->bits_per_pixel / 8 + (
					((int) line.y_top + row) * dst->size_line);
			position_src = (cols + src_x) * src.bits_per_pixel / 8 + (
					floor(scale_factor * row) * src.size_line);
			memcpy((dst->start_area_ptr + position_dst), src.start_area_ptr + position_src,
					4 * sizeof(char));
			cols++;
		}
		row++;
	}
}

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
