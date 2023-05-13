/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   development_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:12:18 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 14:17:28 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

void	display_scene(t_scene *scene)
{
	int		counter;

	ft_printf("Resolution: %d %d\n",
		scene->resolution.width,
		scene->resolution.height);
	ft_printf("North: %s\n", scene->textures[NORTH]);
	ft_printf("East: %s\n", scene->textures[SOUTH]);
	ft_printf("West: %s\n", scene->textures[EAST]);
	ft_printf("East: %s\n", scene->textures[WEST]);
	ft_printf("Sprite: %s\n", scene->textures[SPRITE]);
	ft_printf("Floor color: %d %d %d\n", scene->floor.red,
		scene->floor.green, scene->floor.blue);
	ft_printf("Ceiling color: %d %d %d\n", scene->ceiling.red,
		scene->ceiling.green, scene->ceiling.blue);
	ft_printf("Map size %d %d\n", scene->map.width, scene->map.height);
	counter = 0;
	while (counter < scene->map.height)
	{
		ft_putendl(scene->map.map[counter]);
		counter++;
	}
}
