/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:42:58 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/19 10:43:24 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_walls_object(t_screen *screen, t_list **head);
static void	render_objects(t_screen *screen, t_list *head);

int	rendering_game(t_screen *screen)
{
	t_list		*head;

	handle_movement(screen);
	head = NULL;
	get_walls_object(screen, &head);
	get_sprites(screen, &head);
	sort_objects_by_distance(head, last_node(head));
	render_objects(screen, head);
	check_time(screen);
	swap_frame_screen(screen);
	destroy_list(head);
	return (0);
}

static void	get_walls_object(t_screen *screen, t_list **head)
{
	t_ray		ray;
	t_object	*wall;
	double		angle;

	ray.nbr = 0;
	angle = (double) screen->player.direction - FOV / 2 + 0.00001;
	while (ray.nbr < screen->raycasting_param.max_ray_nbr)
	{
		init_ray(&ray, screen, &angle);
		wall = calculate_wall_projection(screen, &ray);
		append_to_list(wall, head);
		ray.nbr++;
	}
}

static void	render_objects(t_screen *screen, t_list *head)
{
	t_list		*current;
	t_object	*object;

	current = head;
	while (current != NULL)
	{
		object = current->object;
		draw_objects(screen, object);
		current = current->next;
	}
}
