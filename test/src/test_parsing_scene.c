/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:43:41 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/05 17:28:20 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_scene(t_scene scene);
int	map_not_equal(char **map1, char ** map2, int height);
int	compare_t_scene(t_scene scene1, t_scene scene2);
t_scene	build_test_scene(void);

int	main(int argc, char *argv[])
{
	t_scene scene;
	t_scene scene_test;

	if (argc < 2)
		return (0);
	scene_test = build_test_scene();
	parsing_scene(&scene, argv[1]);
	ft_putendl("Comparing scene from parsing with actual scene.");
	ft_printf("Scene from parsing file:\n");
	display_scene(scene);
	ft_printf("\nMade up scene\n");
	display_scene(scene_test);
	if (compare_t_scene(scene, scene_test))
	{
		ft_printf("Parsing test passed");
	}
	else
		ft_putendl("Parsing test failed");
	return (1);
}

t_scene	build_test_scene(void)
{
	char	**map;
	map = malloc(4 * sizeof(char *));
	map[0] = ft_strdup("11111111");
	map[1] = ft_strdup("11002001");
	map[2] = ft_strdup("10000001");
	map[3] = ft_strdup("11111111");
	t_scene scene = {{1920, 1080},
		"./texture/north.png",
		"./texture/south.png",
		"./texture/west.png",
		"./texture/east.png",
		"./texture/sprite.png",
		{220, 100, 0},
		{225, 30, 0},
		{8, 4, map}};
	return scene;
}

void	display_scene(t_scene scene)
{
	int		counter;

	ft_printf("Resolution: %d %d\n", scene.resolution.width, scene.resolution.height);
	ft_printf("North: %s\n", scene.north);
	ft_printf("East: %s\n", scene.east);
	ft_printf("West: %s\n", scene.west);
	ft_printf("East: %s\n", scene.east);
	ft_printf("Sprite: %s\n", scene.sprite);
	ft_printf("Floor color: %d %d %d\n", scene.floor.red,
			scene.floor.green, scene.floor.blue);
	ft_printf("Ceiling color: %d %d %d\n", scene.ceiling.red,
			scene.ceiling.green, scene.ceiling.blue);
	ft_printf("Map size %d %d\n", scene.map.width, scene.map.height);
	counter = 0;
	while (counter < scene.map.height)
	{
		ft_putendl(scene.map.map[counter]);
		counter++;
	}
}

int	compare_t_scene(t_scene scene1, t_scene scene2)
{
	if (scene1.resolution.width != scene2.resolution.width)
		return (0);
	else if (scene1.resolution.height != scene2.resolution.height)
		return (0);
	else if (scene1.ceiling.red != scene2.ceiling.red)
		return (0);
	else if (scene1.ceiling.blue != scene2.ceiling.blue)
		return (0);
	else if (scene1.ceiling.green != scene2.ceiling.green)
		return (0);
	else if (scene1.floor.red != scene2.floor.red)
		return (0);
	else if (scene1.floor.blue != scene2.floor.blue)
		return (0);
	else if (scene1.floor.green != scene2.floor.green)
		return (0);
	else if (!ft_strcmp(scene1.north, scene2.north))
		return (0);
	else if (!ft_strcmp(scene1.south, scene2.south))
		return (0);
	else if (!ft_strcmp(scene1.east, scene2.east))
		return (0);
	else if (!ft_strcmp(scene1.west, scene2.west))
		return (0);
	else if (!ft_strcmp(scene1.sprite, scene2.sprite))
		return (0);
	else if (scene1.map.width != scene2.map.width)
		return (0);
	else if (scene1.map.height != scene2.map.height)
		return (0);
	else if (map_not_equal(scene1.map.map, scene2.map.map, scene1.map.height))
			return (0);
	return (1);
}

int	map_not_equal(char **map1, char ** map2, int height)
{
	int	counter;

	counter = 0;
	while (counter < height)
	{
		if (!ft_strcmp(map1[counter], map2[counter]))
			return (1);
		counter++;
	}
	return (0);
}
