/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:19:38 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/04 14:27:30 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_animated_sprite(t_scene scene, t_anim_sprite *anim_sprite);

void	get_animated_sprites(t_screen *screen, t_list **head)
{
	int			counter;
	int			animation_number;
	int			current_image;
	t_sprite	sprite;

	counter = 0;
	current_image = 0;
	while (counter < screen->scene.anim_sprite_count)
	{
		animation_number = screen->scene.anim_sprites[counter].animation;
		update_animated_sprite(screen->scene,
			&screen->scene.anim_sprites[counter]);
		current_image = screen->scene.anim_sprites[counter].current_img_index;
		sprite = screen->scene.animations[
			animation_number].sprites[current_image];
		sprite.shift = screen->scene.animations[animation_number].shift;
		sprite.coord = screen->scene.anim_sprites[counter].coord;
		build_sprite_objects(screen, sprite, head);
		counter++;
	}
}

void	update_animated_sprite(t_scene scene, t_anim_sprite *anim_sprite)
{
	double	now;

	if (anim_sprite->time == 0)
	{
		anim_sprite->current_img_index = 0;
		anim_sprite->time = clock() / CLOCKS_PER_SEC;
	}
	now = (double) clock() / CLOCKS_PER_SEC;
	if (now - anim_sprite->time > ANIMATION_TIMING)
	{
		if (anim_sprite->current_img_index < (
				scene.animations[anim_sprite->animation].images_nbr - 1))
			anim_sprite->current_img_index++;
		else
			anim_sprite->current_img_index = 0;
		anim_sprite->time = (double) clock() / CLOCKS_PER_SEC;
	}
}
