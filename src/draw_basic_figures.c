/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_basic_figures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:57:50 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/19 11:45:56 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_pixel_on_buffer(t_screen *screen, t_point point);
static int	is_position_outside(int position, t_screen *screen);

void	draw_pixel_on_buffer(t_screen *screen, t_point point)
{
	int		position;
	int		y;
	int		x;
	char	*dst;

	y = screen->buffer.size_line * (int) point.y;
	x = (int) point.x * screen->buffer.bits_per_pixel / 8;
	position = x + y;
	dst = screen->buffer.start_area_ptr + position;
	if (!is_position_outside(position, screen))
		*(unsigned int *)dst = point.color.rgb;
}

static int	is_position_outside(int position, t_screen *screen)
{
	int		size;

	size = screen->buffer.size_line * screen->scene.resolution.height;
	if (position > size || position < 0)
	{
		printf("alert: outside of the buffer");
		return (1);
	}
	return (0);
}

void	draw_rectangle(t_screen *screen, int width, int height, t_point coord)
{
	t_point	point;

	point.color = coord.color;
	point.y = coord.y;
	while (point.y < coord.y + height)
	{
		point.x = coord.x;
		while (point.x < coord.x + width)
		{
			draw_pixel_on_buffer(screen, point);
			point.x++;
		}
		point.y++;
	}
}

void	copy_byte_to_image(char *dst, char *src)
{
	unsigned int	pixel;

	pixel = *(unsigned int *) src;
	if (get_alpha(pixel) <= 0)
		*(unsigned int *) dst = pixel;
}
