/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:04:41 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/05 21:28:42 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

static void	process_line(t_scene *scene, char *line);
static void	parsing_other_element(t_scene *scene, char *path);

void	parsing_scene(t_scene *scene, char *path)
{
	scene->map = parse_map(path);
	parsing_other_element(scene, path);
	check_map(scene->map);
}

void	parsing_other_element(t_scene *scene, char *path)
{
	int		scene_file_descriptor;
	int		next_line_return;
	char	line[150];

	scene_file_descriptor = open(path, O_RDONLY);
	next_line_return = get_next_line(scene_file_descriptor, line);
	while (next_line_return == 1)
	{
		process_line(scene, line);
		next_line_return = get_next_line(scene_file_descriptor, line);
	}
	if (next_line_return == -1)
		ft_printf("Error(parsing_other_element()): problem while reading lines.\n");
	close(scene_file_descriptor);
}

// Parsing functions are in parsing_type_identifier
// Is functions are in parsing_is_types.c
void	process_line(t_scene *scene, char *line)
{
	char	**splited_line;

	splited_line = ft_strsplit(line, ' ');
	if (!ft_strcmp(splited_line[0], "\n"))
		return ;
	else if (!ft_strcmp(splited_line[0], "R"))
		parse_resolution(scene, splited_line);
	else if (is_textures(splited_line[0]))
		parse_textures(scene, splited_line);
	else if (is_color(splited_line[0]))
		parse_colors(scene, splited_line);
	else if (is_map(splited_line[0]))
		return ;
}
