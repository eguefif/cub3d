/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:15:40 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/24 20:41:54 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_animated_sprites(t_screen *screen, t_list **head)
{
	int			counter;
	t_sprite	sprite;

	counter = 0;
	while (counter < screen->scene.anim_count)
	{
		update_animated_sprite(screen->scene,
			&screen->scene.anim_sprites[counter]);
		sprite = build_animated_sprite(screen,
				screen->scene.anim_sprites[counter]);
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

t_sprite	build_animated_sprite(t_screen *screen, t_anim_sprite anim_sprite)
{
	t_sprite	sprite;

	sprite.coord = anim_sprite.coord;
	sprite.shift = anim_sprite.shift;
	sprite.texture = (
			screen->scene.animations[anim_sprite.animation].img_index + (
				anim_sprite.current_img_index));
	return (sprite);
}
