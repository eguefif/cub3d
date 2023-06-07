/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_animations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:51:59 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/04 14:26:40 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	build_anim_sprites(t_anim_sprite *anim,
				int cols, int rows, t_map map);
static int	is_animated_sprite(char cell);
static int	get_animation_number(char anim);

void	looking_for_animated_sprite(t_screen *screen)
{
	int		cols;
	int		rows;
	int		counter;

	rows = 0;
	counter = 0;
	while (rows < screen->scene.map.height)
	{
		cols = 0;
		while (cols < screen->scene.map.width)
		{
			if (is_animated_sprite(screen->scene.map.map[rows][cols]))
			{
				build_anim_sprites(&screen->scene.anim_sprites[counter],
					cols, rows, screen->scene.map);
				counter++;
			}
			cols++;
		}
		rows++;
	}
	screen->scene.anim_sprite_count = counter;
}

static void	build_anim_sprites(t_anim_sprite *anim,
		int cols, int rows, t_map map)
{
	anim->coord.x = (
			cols * SQUARE_SIZE + SQUARE_SIZE / 2);
	anim->coord.y = (
			rows * SQUARE_SIZE + SQUARE_SIZE / 2);
	anim->current_img_index = 0;
	anim->animation = get_animation_number(map.map[rows][cols]);
}

static int	is_animated_sprite(char cell)
{
	if (ft_strchr("3", cell))
		return (1);
	return (0);
}

static int	get_animation_number(char anim)
{
	if (anim == '3')
		return (0);
	return (0);
}
