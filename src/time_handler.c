/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:03:27 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/11 08:13:36 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_time(clock_t start_time)
{
	clock_t			end_time;
	static double	elapsed_time = 0;
	double			difference;

	if (elapsed_time == 0)
		return ;
	else
	{
		end_time = clock();
		elapsed_time = ((double)(end_time - start_time) / CLOCKS_PER_SEC);
		difference = (30 / 60) - elapsed_time;
		if (difference > 0)
			sleep((unsigned int) difference);
	}
}
