/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_information.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:55:57 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/06 19:18:55 by eguefif          ###   ########.fr       */
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

	cols_counter = 0;
	while (cols_counter < screen->scene.map.height)
	{
		row_counter = 0;
		while (row_counter < screen->scene.map.width)
		{
			cell = screen->scene.map.map[cols_counter][row_counter];
			if (is_player(cell))
			{
				screen->raycasting_param.player.x = cols_counter;
				screen->raycasting_param.player.y = row_counter;
				screen->raycasting_param.player.direction = get_direction(cell);
			}
			row_counter++;
		}
		cols_counter++;
	}
}

static int	is_player(char c)
{
	if (!ft_strchr("NSWE", c))
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
