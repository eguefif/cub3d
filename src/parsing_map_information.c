/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_information.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:55:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/16 14:07:32 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	looking_for_player(t_screen *screen);
static void	looking_for_sprite(t_screen *screen);
static int	is_player(char c);
static int	get_direction(char c);
static int	get_sprite_texture(char cell);

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
		return (270);
	else if (c == 'W')
		return (0);
	else if (c == 'S')
		return (90);
	else if (c == 'E')
		return (180);
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
					screen->scene.sprites[sprite_count].coord.x = cols_counter * SQUARE_SIZE + 50;
					screen->scene.sprites[sprite_count].coord.y = row_counter * SQUARE_SIZE + 50;
					screen->scene.sprites[sprite_count].texture = get_sprite_texture(cell);
					sprite_count++;
				}
				else
					printf("Not enough place for sprite in t_scene scene\n");
			}
			cols_counter++;
		}
		row_counter++;
	}
	screen->scene.sprite_count = sprite_count;
}

static int	get_sprite_texture(char cell)
{
	if (ft_strchr("2", cell))
		return (SPRITE);
	return (SPRITE);
}

