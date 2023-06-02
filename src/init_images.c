/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:19:10 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/01 20:04:01 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	init_wall_textures(void *mlx, t_screen *screen)
{
	int		counter;

	counter = 0;
	while (counter < NBR_TEXTURES)
	{
		create_image_from_path(screen->mlx_ptr, &screen->scene.textures[counter]);
		counter++;
	}
}

void	init_animations(t_screen *screen)
{
	int		i;

	i = 0;
	while (i < screen->scene.animation_count)
	{
		get_animation(screen->mlx,
				&screen->scene.animations[i]);
		i++;
	}
}

static void	get_animation(void *mlx, t_animation *animation)
{
	int		i;
	char	path[50];

	i = 0;
	while(i < 4)
	{
		vsprintf(path, "%s%d.xpm", animation->path, i);
		create_image_from_path(mlx, animation->sprites[i].image);
		i++;
	}
}
		
void	init_sprites(t_screen *screen)
{
	int		counter;

	counter = 0;
	while (counter < screen->scene.images_sprite_count)
	{
		create_image_from_path(screen->mlx_ptr,
				screen->scene.sprites[counter].sprite.image);
		counter++;
	}
}
