/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_objects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:49:30 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/04 14:35:33 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	build_object(t_item *item,
				int cols_counter, int rows_counter, char cell);
static void	get_object_image(char cell, t_item *object);
static int	is_object(char cell);

void	looking_for_objects(t_screen *screen)
{
	int		cols;
	int		rows;

	rows = 0;
	screen->scene.items_count = 0;
	while (rows < screen->scene.map.height)
	{
		cols = 0;
		while (cols < screen->scene.map.width)
		{
			if (is_object(screen->scene.map.map[rows][cols]))
			{
				if (screen->scene.items_count < 50)
				{
					build_object(
						&screen->scene.items[screen->scene.items_count],
						cols, rows, screen->scene.map.map[rows][cols]);
					screen->scene.items_count++;
				}
			}
			cols++;
		}
		rows++;
	}
}

static void	build_object(t_item *item, int cols, int rows, char cell)
{
	item->coord.x = (
			cols * SQUARE_SIZE + SQUARE_SIZE / 2);
	item->coord.y = (
			rows * SQUARE_SIZE + SQUARE_SIZE / 2);
	get_object_image(cell, item);
}

static int	is_object(char cell)
{
	if (ft_strchr("2", cell))
		return (1);
	return (0);
}

static void	get_object_image(char cell, t_item *object)
{
	if (ft_strchr("2", cell))
		object->image_number = 0;
	else
		object->image_number = 0;
}
