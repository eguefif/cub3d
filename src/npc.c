/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:35:31 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/06 17:31:40 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	get_npc_type(char *type);
static t_animation	get_npc_animation(t_npc_instance npc,
		t_npc *npc_base);

void	update_npc(t_screen *screen, t_list **objects)
{
	int				counter;
	t_animation		npc;
	t_sprite		sprite;
	int				current_image;

	counter = 0;
	printf("%lu\n", sizeof(screen->scene.ennemies));
	while (counter < screen->scene.npc_instance_counter)
	{
		npc = get_npc_animation(
				screen->scene.ennemies[counter],
				screen->scene.npc);
		update_npc_animated_sprite(&npc);
		current_image = npc.current_img_index;
		sprite = npc.sprites[current_image];
		sprite.shift = screen->scene.animations[animation_number].shift;
		sprite.coord = screen->ennemies[counter].coord;
		build_sprite_objects(screen, sprite, head);
		counter++;
	}
}

static t_animation	get_npc_animation(t_npc_instance npc,
		t_npc *npc_base);
{
	int		npc_type;

	npc_type = get_npc_type(npc.type);
	if (npc.state == DEATH)
		return npc_base[npc_type].death;
	else if (npc.state == WALK)
		return npc_base[npc_type].walk;
	else if (npc.state == IDLE)
		return npc_base[npc_type].idle;
	else if (npc.state == ATTACK)
		return npc_base[npc_type].attack;
	else if (npc.state == PAIN)
		return npc_base[npc_type].pain;
}

static int	get_npc_type(char *type)
{
	if (ft_strcmp(type, "soldier"))
		return (0);
}
