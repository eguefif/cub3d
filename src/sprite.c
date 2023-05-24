/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:15:43 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/24 15:37:02 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_sprite_objects(t_screen *screen, t_sprite sprite,
			t_list **objects);
void	calculate_projection_height(t_screen *screen,
			t_sprite sprite, t_object *sprite_line, double delta);
double	get_delta_angle(t_player player, t_sprite sprite);

void	get_sprites(t_screen *screen, t_list **objects)
{
	int		sprite_counter;

	sprite_counter = 0;
	while (sprite_counter < screen->scene.sprite_count)
	{
		build_sprite_objects(screen,
			screen->scene.sprites[sprite_counter], objects);
		sprite_counter++;
	}
}

void	build_sprite_objects(t_screen *screen,
		t_sprite sprite, t_list **objects)
{
	double		delta;
	t_object	*sprite_object;
	double		delta_rays;

	sprite_object = (t_object *) malloc(sizeof(t_object));
	delta = get_delta_angle(screen->player, sprite);
	if (delta > FOV / 2 || delta < -FOV / 2)
		return ;
	delta_rays = delta / screen->raycasting_param.delta_angle;
	calculate_projection_height(screen, sprite, sprite_object, delta_rays);
	sprite_object->buffer_coord.x = (screen->raycasting_param.max_ray_nbr / 2 + 
			delta_rays) * screen->raycasting_param.scale;
	sprite_object->buffer_coord.y = screen->scene.resolution.height / 2 - 
			sprite_object->height + sprite_object->height * sprite.shift;
	sprite_object->texture = sprite.texture;
	sprite_object->type = 's';
	sprite_object->distance = sprite_object->distance * cos(degree_to_radian(delta));
	sprite_object->width = sprite_object->height * screen->scene.sprite_images[sprite.texture]->ratio;
	sprite_object->buffer_coord.x = sprite_object->buffer_coord.x - sprite_object->width / 2;
	if (sprite_object->buffer_coord.x + sprite_object->width > 0 && (
			sprite_object->buffer_coord.x < screen->scene.resolution.width))
		append_to_list(sprite_object, objects);
}

void	calculate_projection_height(t_screen *screen,
		t_sprite sprite, t_object *sprite_line, double delta)
{
	sprite_line->distance = calculate_distance(
			screen->player.coord, sprite.coord);
	sprite_line->distance = sprite_line->distance * cos(degree_to_radian(
		(double)((FOV / 2 + delta) * screen->raycasting_param.delta_angle)));
	sprite_line->height = screen->raycasting_param.projection_var / (
			sprite_line->distance);
}

double	get_delta_angle(t_player player, t_sprite sprite)
{
	double	theta;
	double	delta;
	int		dx;
	int		dy;

	dx = sprite.coord.x - player.coord.x;
	dy = sprite.coord.y - player.coord.y;
	theta = atan2(dy, dx);
	delta = theta - degree_to_radian(player.direction);
	if ((dx > 0 && player.direction > 180) || (dx < 0 && dy < 0))
		delta += (2 * M_PI);
	return ((double) delta * 180 / M_PI);
}
