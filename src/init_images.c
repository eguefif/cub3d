/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:19:10 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/02 15:15:37 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_animation(void *mlx, t_animation *animation);

void	init_wall_textures(t_screen *screen)
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
	while (i < screen->scene.anim_count)
	{
		get_animation(screen->mlx_ptr,
				&screen->scene.animations[i]);
		i++;
	}
}

static void	get_animation(void *mlx, t_animation *animation)
{
	int		i;

	i = 0;
	while(i < 4)
	{
		animation->sprites[i].image.path[0] = '\0';
		ft_strcpy(animation->sprites[i].image.path,
				animation->path);
		ft_strcat(animation->sprites[i].image.path, ft_itoa(i));
		ft_strcat(animation->sprites[i].image.path, ".xpm");
		create_image_from_path(mlx, &animation->sprites[i].image);
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
				&screen->scene.sprites[counter].image);
		counter++;
	}
}
