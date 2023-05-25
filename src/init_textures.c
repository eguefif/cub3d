/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:19:10 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/24 17:27:04 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_animated_sprite_images(t_scene *scene, t_animation *animation);

void	init_textures(t_screen *screen)
{
	int		counter;

	counter = 0;
	while (counter < NBR_TEXTURES)
	{
		create_image_from_path(screen->mlx_ptr, &screen->scene.textures[counter]);
		counter++;
	}
}

void	init_animated_sprites(t_screen *screen)
{
	int		counter;

	counter = 0;
	while (counter < screen->scene.anim_count)
	{
		screen->scene.animations[counter].img_index = screen->scene.images_sprite_count;
		get_animated_sprite_images(
				&screen->scene,
				&screen->scene.animations[counter]);
		screen->scene.animations[counter].timing = 0;
		counter++;
	}
}

static void	get_animated_sprite_images(t_scene *scene, t_animation *animation)
{
	int		*counter;
	int		total_image;

	counter = &scene->images_sprite_count;
	total_image = *counter + animation->images_nbr;
	while (*counter < total_image)
	{
		scene->sprite_images[*counter] = (t_image *) malloc(sizeof(t_image));
		sprintf(scene->sprite_images[*counter]->path, "%s%d.xpm", animation->path, *counter);
		(*counter)++;
	}
}

void	init_sprites(t_screen *screen)
{
	int		counter;

	counter = 0;
	while (counter < screen->scene.images_sprite_count)
	{
		create_image_from_path(screen->mlx_ptr, screen->scene.sprite_images[counter]);
		counter++;
	}
}
