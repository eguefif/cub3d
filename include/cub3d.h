/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:45:35 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/05 20:20:06 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# define MAX_MAP_WIDTH 500

typedef struct s_resolution
{
	int	width;
	int	height;
}		t_resolution;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}			t_color;

typedef struct s_texture
{
	char	name[15];
	char	path[50];
}			t_texture;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}			t_map;

typedef struct s_scene
{
	t_resolution	resolution;
	char			north[50];
	char			south[50];
	char			west[50];
	char			east[50];
	char			sprite[50];
	t_color			floor;
	t_color			ceiling;
	t_map			map;
}					t_scene;

void	handle_error_reading_line(char *line);

// Development functions
void	display_scene(t_scene scene);
#endif
