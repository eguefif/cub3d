/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_information.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:55:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/19 11:34:51 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	looking_for_player(t_screen *screen);
static void	looking_for_sprite(t_screen *screen);
static void	add_sprite(t_screen *screen, int x, int y, int count, char cell);
static int	is_player(char c);
static int	get_direction(char c);
static void	get_sprite_texture(char cell, t_sprite *sprite);

void	parsing_map_information(t_screen *screen)
{
	looking_for_player(screen);
	looking_for_sprite(screen);
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
					add_sprite(screen, cols_counter,
						row_counter, sprite_count, cell);
					sprite_count++;
				}
			}
			cols_counter++;
		}
		row_counter++;
	}
	screen->scene.sprite_count = sprite_count;
}

static void	add_sprite(t_screen *screen, int x, int y, int count, char cell)
{
	screen->scene.sprites[count].coord.x = y * SQUARE_SIZE;
	screen->scene.sprites[count].coord.y = x * SQUARE_SIZE;
	get_sprite_texture(cell, &screen->scene.sprites[count]);
}

static void	get_sprite_texture(char cell, t_sprite *sprite)
{
	if (ft_strchr("2", cell))
	{
		sprite->texture = SPRITE;
		sprite->shift = 0.8;
	}
}
