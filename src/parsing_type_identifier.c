/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_type_identifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:13:48 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/05 20:56:24 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	check_if_rgb_number(char **rgb);
int	is_string_number(char *string);

void	parse_resolution(t_scene *scene, char **splited_line)
{
	if (is_string_number(splited_line[1]))
		scene->resolution.width = ft_atoi(splited_line[1]);
	else
	{
		perror("Error in parse_resolution(): parameter is not a number\n");
		exit(0);
	}
	if (is_string_number(splited_line[2]))
		scene->resolution.height = ft_atoi(splited_line[2]);
	else
	{
		perror("Error in parse_resolution(): parameter is not a number\n");
		exit(0);
	}
}

void	parse_textures(t_scene *scene, char **splited_line)
{
	if (!ft_strcmp(splited_line[0], "NO"))
		ft_strncpy(scene->north, splited_line[1], 49);
	else if (!ft_strcmp(splited_line[0], "SO"))
		ft_strncpy(scene->south, splited_line[1], 49);
	else if (!ft_strcmp(splited_line[0], "EA"))
		ft_strncpy(scene->east, splited_line[1], 49);
	else if (!ft_strcmp(splited_line[0], "WE"))
		ft_strncpy(scene->west, splited_line[1], 49);
	else if (!ft_strcmp(splited_line[0], "S"))
		ft_strncpy(scene->sprite, splited_line[1], 49);
}

void	parse_colors(t_scene *scene, char **splited_line)
{
	char	**rgb;

	rgb = ft_strsplit(splited_line[1], ',');
	if (check_if_rgb_number(rgb))
	{
		if (ft_strcmp(splited_line[0], "C"))
		{
			scene->ceiling.red = ft_atoi(rgb[0]);
			scene->ceiling.green = ft_atoi(rgb[1]);
			scene->ceiling.blue = ft_atoi(rgb[2]);
		}
		else if (ft_strcmp(splited_line[0], "F"))
		{
			scene->floor.red = ft_atoi(rgb[0]);
			scene->floor.green = ft_atoi(rgb[1]);
			scene->floor.blue = ft_atoi(rgb[2]);
		}
	}
	else
	{
		perror("Error in parse_colors(): RGB is not a color.\n");
		exit(1);
	}
}

int	check_if_rgb_number(char **rgb)
{
	if (!is_string_number(rgb[0]))
		return (0);
	else if (!is_string_number(rgb[1]))
		return (0);
	else if (!is_string_number(rgb[2]))
		return (0);
	return (1);
}

int	is_string_number(char *string)
{
	while (*string != '\0')
	{
		if (!ft_isdigit(*string))
			return (0);
		string++;
	}
	return (1);
}
