/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_npc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:37:08 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/06 17:13:22 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	get_npc_type(char *type, char cell);
static int	is_npc(char cell);

void	looking_for_npc(t_scene *scene)
{
	int		rows;
	int		cols;
	char	cell;
	int		counter;

	rows = 0;
	counter = 0;
	while (rows < scene->map.height)
	{
		cols = 0;
		while (cols < scene->map.width)
		{
			cell = scene->map.map[rows][cols];
			if (is_npc(cell))
			{
				scene->ennemies[counter].coord.x = (
						rows * SQUARE_SIZE);
				scene->ennemies[counter].coord.x = (
						cols * SQUARE_SIZE);
				scene->ennemies[counter].state= IDLE;
				scene->ennemies[counter].life = 100;
				get_npc_type(scene->ennemies[counter].type,
							cell);
				counter++;
			}
			cols++;
		}
		rows++;
	}
	scene->npc_instance_counter = counter;
}

static void	get_npc_type(char *type, char cell)
{
	if (cell == 'Z')
		ft_strcpy(type, "soldier");
}

static int	is_npc(char cell)
{
	if (ft_strchr("Z", cell))
		return (1);
	return (0);
}
