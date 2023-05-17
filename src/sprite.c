/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:15:43 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/16 15:58:20 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_sprite_object(t_screen *screen, t_list **objects, t_sprite sprite);
void	calculate_sprite_height_size(t_point player, t_point sprite, t_object *obj);

void	get_sprites(t_screen *screen, t_list **objects)
{
	int		sprite_counter;

	sprite_counter = 0;
	while (sprite_counter < screen->scene.sprite_count)
	{
		buil_sprite_object(screen, objects, screen->scene.sprite[sprite_counter]);
		sprite_counter++;
	}
}

void	build_sprite_object(t_screen *screen, t_list **objects, t_sprite sprite)
{
	t_object	sprite_chunk;
	int			chunk_count;

	sprite_chunk = (t_object*) malloc(sizeof(t_object));
	calculate_sprite_height_size(screen->player.coord, sprite.coord);
}

void	calculate_sprite_height_size(t_screen *screen, t_sprite sprite, t_object *obj)
{
	obj->distance = calculate_distance(screen->player.coord, sprite.coord);
	obj->ray_nbr = 0;
}
