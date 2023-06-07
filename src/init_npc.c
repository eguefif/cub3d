/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_npc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:51:22 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/05 19:32:21 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_anim_npc(void *mlx, t_npc *npc);

void	init_npc_animation(t_screen *screen)
{
	int		counter;

	counter = 0;
	while (counter < screen->scene.npc_counter)
	{
		get_anim_npc(screen->mlx_ptr, &screen->scene.npc[counter]);
		counter++;
	}
}

static void	get_anim_npc(void *mlx, t_npc *npc)
{
	get_animation(mlx, &npc->idle);
	get_animation(mlx, &npc->walk);
	get_animation(mlx, &npc->attack);
	get_animation(mlx, &npc->death);
	get_animation(mlx, &npc->pain);
}
