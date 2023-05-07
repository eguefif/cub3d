/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:45:17 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/06 14:39:13 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_arg(int argc);
void	main_loop(t_screen *screen);

int	main(int argc, char *argv[])
{
	t_screen	screen;

	check_arg(argc);
	init_game(&screen, argv[1]);
	main_loop(&screen);
	terminate_game(&screen);
	return (1);
}

int	check_arg(int argc)
{
	if (argc < 2)
	{
		ft_putendl("Usage: cub3d PATH_TO_SCENE");
		exit(0);
	}
	return (1);
}

void	main_loop(t_screen *screen)
{
	mlx_key_hook(screen->window, keyboard_manager, screen);
	rendering_game(screen);
	mlx_loop(screen->mlx_ptr);
}
