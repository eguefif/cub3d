/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:45:17 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/05 20:20:36 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	check_arg(int argc);

int	main(int argc, char *argv[])
{
	t_scene		scene;

	if (check_arg(argc))
		parsing_scene(&scene, argv[1]);
	return (1);
}

int	check_arg(int argc)
{
	if (argc < 2)
	{
		ft_putendl("Usage: cub3d PATH_TO_SCENE");
		return (0);
	}
	return (1);
}
