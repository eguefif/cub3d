/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:54:20 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/04 14:16:35 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_sprites(t_scene *scene, char **splited_line)
{
	ft_strncpy(
		scene->sprites[scene->images_sprite_count].image.path,
		splited_line[1], 49);
	scene->sprites[scene->images_sprite_count].shift = (double) ft_atoi(
			splited_line[2]) / 100;
	scene->images_sprite_count += 1;
}

void	parsing_animations(t_scene *scene, char **splited_line)
{
	ft_strncpy(scene->animations[scene->anim_count].path,
		splited_line[1], 49);
	scene->animations[scene->anim_count].images_nbr = ft_atoi(
			splited_line[2]);
	scene->animations[scene->anim_count].shift = (double) ft_atoi(
			splited_line[3]) / 100;
	scene->animations[scene->anim_count].timing = (double) ft_atoi(
			splited_line[4]) / 100;
	scene->anim_count++;
}
