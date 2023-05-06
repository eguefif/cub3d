/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:00:04 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/05 21:23:44 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

static int	biggest_line(int line_width, int map_width);
static void	get_map_size(t_map *map, char *path);

t_map	parse_map(char *path)
{
	int		counter;
	char	line[MAX_MAP_WIDTH];
	int		scene_file_descriptor;
	t_map	map;

	get_map_size(&map, path);
	scene_file_descriptor = open(path, O_RDONLY);
	map.map = (char **) malloc(map.height * sizeof(char *));
	counter = 0;
	while (counter < map.height)
	{
		get_next_line(scene_file_descriptor, line);
		if (is_map(line))
		{
			map.map[counter] = ft_strdup(line);
			counter++;
		}
	}
	close(scene_file_descriptor);
	return (map);
}

void	get_map_size(t_map *map, char *path)
{
	int		scene_file_descriptor;
	int		next_line_return_value;
	char	line[MAX_MAP_WIDTH];
	int		line_width;

	scene_file_descriptor = open(path, O_RDONLY);
	map->height = 0;
	map->width = 0;
	next_line_return_value = get_next_line(scene_file_descriptor, line);
	while (next_line_return_value == 1)
	{
		if (is_map(line))
		{
			map->height++;
			line_width = ft_strlen(line);
			map->width = biggest_line(line_width, map->width);
		}
		next_line_return_value = get_next_line(scene_file_descriptor, line);
	}
	close(scene_file_descriptor);
}

int	biggest_line(int line_width, int map_width)
{
	if (line_width >= map_width)
		return (line_width);
	else
		return (map_width);
}
