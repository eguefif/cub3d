/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:15:40 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/22 17:31:48 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	get_animated_sprites(t_screen *screen, t_list **head)
{
	int			counter;
	t_sprite	sprite;

	while (counter < screen->scene.anim_count)
	{
		sprite = build_animated_sprite(screen->scene.anim_sprites[counter]);
		build_sprite_objects(screen, sprite, head);
		counter++;
	}
}

t_sprite	build_animated_sprite(t_anim_sprite anim_sprite)
{
	t_sprite	sprite;

	sprite.coord = anim_sprite.coord;
	sprite.shift = 0.25;
	sprite.texture = anim_sprite.animation;
	return (sprite);
}
