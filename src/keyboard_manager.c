/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:11:16 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/06 19:20:06 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keyboard_manager(int key, t_screen *screen)
{
	if (key == ESCAPE)
	{
		terminate_game(screen);
		exit(1);
	}
	return (1);
}	
