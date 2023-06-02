/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_information.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:55:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/01 20:12:42 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	looking_for_player(t_screen *screen);
static void	looking_for_objects(t_screen *screen);
static int	is_player(char c);
static int	get_direction(char c);
static void	get_object_image(char cell, t_sprite *object);
static void	looking_for_animated_sprite(t_screen *screen);
static int	is_animated_sprite(char cell);
static int	get_animation_number(char anim)
static int	is_object(char cell);

void	parsing_map_information(t_screen *screen)
{
	looking_for_player(screen);
	looking_for_objects(screen);
	looking_for_animated_sprite(screen);
}
static void	looking_for_animated_sprite(t_screen *screen)
{
	int		cols;
	int		rows;
	int		counter;

	rows = 0;
	counter = 0;
	while (rows < screen->scene.map.height)
	{
		cols = 0;
		while (cols < screen->scene.map.width)
		{
			if (is_animated_sprite(screen->scene.map.map[rows][cols]))
			{
				screen->scene.anim_sprites[counter].coord.x = (
						cols * SQUARE_SIZE + SQUARE_SIZE / 2);
				screen->scene.anim_sprites[counter].coord.y = (
						rows * SQUARE_SIZE + SQUARE_SIZE / 2);
				screen->scene.anim_sprites[counter].current_img_index = 0;
				screen->scene.anim_sprites[counter].animation = get_animation_number(
						screen->scene.map.map[rows][cols]);
				counter++;
			}
			cols++;
		}
		rows++;
	}
	screen->scene.anim_count = counter;
}

static int	is_animated_sprite(char cell)
{
	if (ft_strchr("3", cell))
		return (1);
	return (0);
}

static int	get_animation_number(char anim)
{
	if (anim == '3')
		return (0);
	return (0);
}

static void	looking_for_player(t_screen *screen)
{
	int		cols_counter;
	int		row_counter;
	char	cell;

	row_counter = 0;
	while (row_counter < screen->scene.map.height)
	{
		cols_counter = 0;
		while (cols_counter < screen->scene.map.width)
		{
			cell = screen->scene.map.map[row_counter][cols_counter];
			if (is_player(cell))
			{
				screen->player.coord.x = cols_counter * SQUARE_SIZE + 15;
				screen->player.coord.y = row_counter * SQUARE_SIZE + 15;
				screen->player.direction = get_direction(cell);
				screen->player.direction_movement = 0;
				screen->player.movement = 0;
				screen->scene.map.map[row_counter][cols_counter] = '0';
				return ;
			}
			cols_counter++;
		}
		row_counter++;
	}
}

static int	is_player(char c)
{
	if (ft_strchr("NSWE", c))
		return (1);
	return (0);
}

static int	get_direction(char c)
{
	if (c == 'N')
		return (90);
	else if (c == 'W')
		return (180);
	else if (c == 'S')
		return (270);
	else if (c == 'E')
		return (0);
	return (0);
}

static void	looking_for_objects(t_screen *screen)
{
	int		cols_counter;
	int		row_counter;
	char	cell;
	int		sprite_count;

	row_counter = 0;
	sprite_count = 0;
	while (row_counter < screen->scene.map.height)
	{
		cols_counter = 0;
		while (cols_counter < screen->scene.map.width)
		{
			cell = screen->scene.map.map[row_counter][cols_counter];
			if (is_object(cell))
			{
				if (sprite_count < 50)
				{
					screen->scene.items[sprite_count].coord.x = (
							cols_counter * SQUARE_SIZE + SQUARE_SIZE / 2)
					screen->scene.items[sprite_count].coord.y = (
							row_counter * SQUARE_SIZE + SQUARE_SIZE / 2);
					get_object_image(cell, &screen->scene.items[sprite_count]);
					sprite_count++;
				}
			}
			cols_counter++;
		}
		row_counter++;
	}
	screen->scene.items_count = sprite_count;
}

static int	is_object(char cell)
{
	if (ft_strchr("2", cell))
		return (1);
	return (0);
}

static void	get_object_image(char cell, t_sprite *object)
{
	if (ft_strchr("2", cell))
		object->image_number = 0;
	else
		object->image_number = 0;
}
