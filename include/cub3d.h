/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:45:35 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/11 20:28:33 by eguefif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "time.h"
# define MAX_MAP_WIDTH 500
# define WINDOW_TITLE "Cub3d"
# define FOV 60
# define SQUARE_SIZE 100
# define NBR_TEXTURES 5
# define PLAYER_SIZE 4
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define SPRITE 4


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

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}			t_map;

typedef struct s_image
{
	void	*img_ptr;
	char	path[50];
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*start_area_ptr;
}			t_image;

typedef struct s_scene
{
	t_resolution	resolution;
	t_color			floor;
	t_color			ceiling;
	t_color			wall;
	t_map			map;
	t_image			textures[NBR_TEXTURES];
}					t_scene;

typedef struct s_point
{
	double	x;
	double	y;
	t_color	color;
}			t_point;

typedef struct s_raycast_line
{
	t_color	top_color;
	t_color	mid_color;
	t_color	bot_color;
	double	x;
	double	y_top;
	double	y_bot;
}			t_raycast_line;

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
	t_point	coord;
	double	direction;
	double	direction_movement;
	double	movement;
}			t_player;

typedef struct s_projection_plane
{
	int		width;
	int		height;
	int		player_plane_distance;
}			t_projection_plane;

typedef struct s_raycasting_parameter
{
	double					field_of_view;
	t_projection_plane		projection_plane;
	double					angle_subsequent_rays;
	double					projection_var;
}							t_raycasting_parameter;

typedef struct s_screen
{
	void					*mlx_ptr;
	void					*window;
	t_player				player;
	t_scene					scene;
	t_screen_buffer			buffer;
	t_raycasting_parameter	raycasting_param;
}							t_screen;

typedef struct s_ray_check
{
	t_point	coord;
	double	distance;
}			t_ray_check;

typedef struct s_ray
{
	int			nbr;
	double		angle;
	double		cosinus;
	double		sinus;
	double		dx;
	double		dy;
	double		d_depth;
	int			max_step;
	t_point		check_position;
	t_player	player;
	t_ray_check	vertical_check;
	t_ray_check	horizontal_check;
	t_ray_check	wall_point;
}				t_ray;

//Init and terminating functions int init*.c and terminate.c
void	init_game(t_screen *screen, char *path, int two_d);
void	init_raycasting(t_screen *screen);
void	init_screen_buffer(t_screen *screen);
void	init_textures(t_screen *screen);
void	parsing_map_information(t_screen *screen);
int		terminate_game(t_screen *screen);

// Main loop function in keyboard_manager.c rendering.c and player_movement.c
int		handle_pressedkey(int key, t_screen *screen);
int		handle_releasedkey(int key, t_screen *screen);
int		rendering_game(t_screen *screen);
int		rendering_game_2d(t_screen *screen);
void	handle_movement(t_screen *screen);
void	check_time(clock_t start_time);

// graphic functions using mlx in buffering and draw_basic_figure
void	swap_frame_screen(t_screen *screen);
void	draw_raycasting_vertical_line(t_screen *screen,
			t_raycast_line line);
void	draw_pixel_on_buffer(t_screen *screen, t_point point);
int		get_color(t_screen *screen, t_color color);

// Ray functions in raycasting files
void		init_ray(t_ray *ray, t_screen *screen);
void		get_dist_to_vertical_wall(t_map map, t_ray *ray);
void		get_dist_to_horizontal_wall(t_map map, t_ray *ray);
int			check_for_wall(t_map map, t_point point);
double		degree_to_radian(double angle);
int			calculate_distance(t_point player, t_point wall);
t_ray_check	get_shorter_ray(t_ray_check ray1, t_ray_check ray2);
void		calculate_wall_distance(t_screen *screen, t_ray *ray);

// Error functions in error files
void	handle_error(char *message);
// Functions for 2d model
void	draw_2d_model(t_screen *screen);
void	draw_2d_ray(t_screen *screen, t_ray ray);

// Development functions
void	display_scene(t_scene *scene);
#endif
