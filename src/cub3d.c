/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:19:17 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/04 11:19:19 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_arg(int argc);
static void	run_3d_engine(t_screen *screen);

int	main(int argc, char *argv[])
{
	t_screen	screen;

	check_arg(argc);
	init_game(&screen, argv[1]);
	run_3d_engine(&screen);
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

static void	run_3d_engine(t_screen *screen)
{
	mlx_mouse_hide(screen->mlx_ptr, screen->window);
	mlx_hook(screen->window, 2, 1L << 0, handle_pressedkey, screen);
	mlx_hook(screen->window, 3, 1L << 1, handle_releasedkey, screen);
	mlx_do_key_autorepeatoff(screen->mlx_ptr);
	mlx_hook(screen->window, 17, 0, terminate_game, screen);
	mlx_mouse_hook(screen->window, mouse_manager, screen);
	mlx_loop_hook(screen->mlx_ptr, rendering_game, screen);
	mlx_loop(screen->mlx_ptr);
}
