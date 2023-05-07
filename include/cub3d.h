/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:45:35 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/06 19:40:29 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# define MAX_MAP_WIDTH 500
# define WINDOW_TITLE "Cub3d"
# define ESCAPE 65307
# define FOV 60
# define SQUARE_SIZE 64

typedef struct s_resolution
{
	int	width;
	int	height;
}		t_resolution;

typedef struct s_color
{
	int					red;
	int					green;
	int					blue;
	unsigned int		rgb;
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
	t_color			wall;
	t_map			map;
}					t_scene;

typedef struct s_point
{
	int		x;
	int		y;
	t_color	color;
}			t_point;

typedef struct s_raycasting_vertical_line
{
	t_color	top_color;
	t_color	mid_color;
	t_color	bot_color;
	int		x;
	int		y_top;
	int		y_bot;
}			t_raycasting_vertical_line;

typedef struct s_screen_buffer
{
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*start_area_ptr;
}			t_screen_buffer;

typedef struct s_player
{
	int		x;
	int		y;
	int		direction;
}			t_player;

typedef struct s_projection_plane
{
	int		width;
	int		height;
	int		player_plane_distance;
}			t_projection_plane;

typedef struct s_raycasting_parameter
{
	t_player				player;
	int						field_of_view;
	t_projection_plane		projection_plane;
	double					angle_subsequent_rays;
}				t_raycasting_parameter;

typedef struct s_screen
{
	void					*mlx_ptr;
	t_scene					scene;
	void					*window;
	t_screen_buffer			buffer;
	t_raycasting_parameter	raycasting_param;
}							t_screen;

void	init_game(t_screen *screen, char *path);
void	init_raycasting(t_screen *screen);
void	parsing_map_information(t_screen *screen);
void	init_screen_buffer(t_screen *screen);
void	terminate_game(t_screen *screen);
int		keyboard_manager(int key, t_screen *screen);
void	rendering_game(t_screen *screen);
void	draw_raycasting_vertical_line(t_screen *screen,
			t_raycasting_vertical_line line);
void	handle_error(char *message);

// Development functions
void	display_scene(t_scene *scene);
#endif
