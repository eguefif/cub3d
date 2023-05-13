/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_information.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:55:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 14:18:04 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	looking_for_player(t_screen *screen);
static int	is_player(char c);
static int	get_direction(char c);

void	parsing_map_information(t_screen *screen)
{
	looking_for_player(screen);
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
