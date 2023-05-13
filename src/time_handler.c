/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:03:27 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/13 07:58:31 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_time(t_screen *screen)
{
	clock_t			end_time;
	static clock_t	start_time = 0;
	double			elapsed_time;
	double			difference;

	if (start_time == 0)
	{
		start_time = clock();
	}
	else
	{
		end_time = clock();
		elapsed_time = ((double)(end_time - start_time) / CLOCKS_PER_SEC);
		difference = (FPS / 60) - elapsed_time;
		screen->elapsed = elapsed_time;
		if (difference > 0)
		{
			sleep((unsigned int) difference);
		}
		start_time = clock();
	}
}
