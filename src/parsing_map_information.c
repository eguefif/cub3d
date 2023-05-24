/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_information.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:55:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/22 17:36:13 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	looking_for_player(t_screen *screen);
static void	looking_for_sprite(t_screen *screen);
static int	is_player(char c);
static int	get_direction(char c);
static void	get_sprite_texture(char cell, t_sprite *sprite);
static void	looking_for_animated_sprite(t_screen *screen);

void	parsing_map_information(t_screen *screen)
{
	looking_for_player(screen);
	looking_for_sprite(screen);
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

			if (screen->scene.map.map[rows][cols] == '3')
			{
				screen->scene.anim_sprites[counter].coord.x = cols * SQUARE_SIZE + SQUARE_SIZE / 2;
				screen->scene.anim_sprites[counter].coord.y = rows * SQUARE_SIZE + SQUARE_SIZE / 2;
				counter++;
			}
			cols++;
		}
		rows++;
	}
	screen->scene.anim_count = counter;
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

static void	looking_for_sprite(t_screen *screen)
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
			if (ft_strchr("2", cell))
			{
				if (sprite_count < 50)
				{
					screen->scene.sprites[sprite_count].coord.x = cols_counter * SQUARE_SIZE + SQUARE_SIZE / 2;
					screen->scene.sprites[sprite_count].coord.y = row_counter * SQUARE_SIZE + SQUARE_SIZE / 2;
					get_sprite_texture(cell, &screen->scene.sprites[sprite_count]);
					sprite_count++;
				}
			}
			cols_counter++;
		}
		row_counter++;
	}
	screen->scene.sprite_count = sprite_count;
}

static void	get_sprite_texture(char cell, t_sprite *sprite)
{
	if (ft_strchr("2", cell))
	{
		sprite->texture = 0;
		sprite->shift = 0.75;
	}
}
