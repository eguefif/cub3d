/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:39:48 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/05 21:31:04 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

static void	check_if_map_is_closed(t_map map);
static void	check_if_map_countain_starting_point(t_map map);
static int	is_starting_point(char point);
static void	is_line_a_wall(char *line, int width);

void	check_map(t_map map)
{
	check_if_map_is_closed(map);
	check_if_map_countain_starting_point(map);
}

void	check_if_map_is_closed(t_map map)
{
	int		row_counter;

	is_line_a_wall(map.map[0], map.width);
	is_line_a_wall(map.map[map.height - 1], map.width);
	row_counter = 0;
	while (row_counter < map.height)
	{
		if (map.map[row_counter][0] != '1' ||
				map.map[row_counter][map.width] != '1')
		{
			ft_printf("Error parsing: the map is not closed.\n");
			exit(-1);
		}
		row_counter++;
	}
}

static void	is_line_a_wall(char *line, int width)
{
	int		counter;

	counter = 0;
	while (counter < width)
	{
		if (line[counter] != '1')
		{
			ft_printf("Error parsing: the map is not closed.\n");
			exit(-1);
		}
		counter++;
	}
}

void	check_if_map_countain_starting_point(t_map map)
{
	int		row_counter;
	int		cols_counter;

	row_counter = 0;
	while (row_counter < map.height)
	{
		cols_counter = 0;
		while (cols_counter < map.width)
		{
			if (is_starting_point(map.map[row_counter][cols_counter]))
				return ;
			cols_counter++;
		}
		row_counter++;
	}
	ft_printf("Error parsing: the map does not contain starting point.\n");
	exit(-1);
}

int	is_starting_point(char point)
{
	if (ft_strchr("NSEW", point))
		return (1);
	return (0);
}
