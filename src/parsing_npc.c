/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_npc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:42:53 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/05 19:39:44 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_animation_npc(int nbr_files,
				char	*base_path,
				char *action_path,
				t_animation *anim);

void	parsing_npc(t_scene *scene, char **splited_line)
{
	ft_strcpy(scene->npc[scene->npc_counter].name, splited_line[1]);
	set_animation_npc(ft_atoi(splited_line[3]),
		splited_line[2], "idle/",
		&scene->npc[scene->npc_counter].idle);
	set_animation_npc(ft_atoi(splited_line[4]),
		splited_line[2], "walk/",
		&scene->npc[scene->npc_counter].walk);
	set_animation_npc(ft_atoi(splited_line[5]),
		splited_line[2], "death/",
		&scene->npc[scene->npc_counter].death);
	set_animation_npc(ft_atoi(splited_line[6]),
		splited_line[2], "attack/",
		&scene->npc[scene->npc_counter].attack);
	set_animation_npc(ft_atoi(splited_line[7]),
		splited_line[2], "pain/",
		&scene->npc[scene->npc_counter].pain);
	scene->npc_counter++;
}

static void	set_animation_npc(int nbr_files,
								char *base_path,
								char *action_path,
								t_animation *anim)
{
	char	path[100];

	anim->images_nbr = nbr_files;
	ft_strcpy(path, base_path);
	ft_strcat(path, action_path);
	ft_strcpy(anim->path, path);
}
