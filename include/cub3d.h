/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:45:35 by eguefif           #+#    #+#             */
/*   Updated: 2023/05/16 12:55:48 by eguefif          ###   ########.fr       */
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
# define RESCALE_WIDTH 1
# define MAX_MAP_WIDTH 500
# define WINDOW_TITLE "Cub3d"
# define FOV 66
# define PROJECTION_PLANE_DST 350
# define SQUARE_SIZE 192
# define PLAYER_SIZE 20
# define NBR_TEXTURES 6
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define SPRITE 4
# define SKY 5
# define SPEED 5
# define ROT_SPEED 3
# define FPS 30


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
	t_sprite		sprites[50];
}					t_scene;

typedef struct s_point
{
	double	x;
	double	y;
	t_color	color;
}			t_point;

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
	double					elapsed;
	t_player				player;
	t_scene					scene;
	t_screen_buffer			buffer;
	t_raycasting_parameter	raycasting_param;
}							t_screen;

typedef struct s_object
{
	t_point	coord;
	t_point	buffer_coord;
	int		texture;
	double	height;
	double	distance;
	double	texture_offset;
	t_point	subsurface;
	double	subsurface_height;
	double	scale_factor;
	double	offset;
	int		ray_nbr;
}			t_object;

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
	t_object	vertical_check;
	t_object	horizontal_check;
}				t_ray;

typedef struct s_list
{
	t_object		*object;
	struct s_list	*next;
}			t_list;

// List handling functions in list.c
t_list	*init_list(void);
void	append_to_list(t_object *object, t_list **head);
void	destroy_list(t_list *first);

//Init and terminating functions in parsing_*.c, init*.c and terminate.c
void	init_game(t_screen *screen, char *path, int two_d);
void	init_raycasting(t_screen *screen);
void	init_screen_buffer(t_screen *screen);
void	init_textures(t_screen *screen);
void	parsing_map_information(t_screen *screen);
int		terminate_game(t_screen *screen);

// Main loop function in keyboard_manager.c rendering.c and player_movement.c time.c
int		handle_pressedkey(int key, t_screen *screen);
int		handle_releasedkey(int key, t_screen *screen);
int		rendering_game(t_screen *screen);
void	handle_movement(t_screen *screen);
void	check_time(t_screen *screen);

// graphic functions using mlx in buffering.c and draw_basic_figure.
void	swap_frame_screen(t_screen *screen);
void	draw_pixel_on_buffer(t_screen *screen, t_point point);
void	draw_rectangle(t_screen *screen, int width, int height, t_point coord);
int		get_color(t_screen *screen, t_color color);
void	copy_byte_to_image(char *dst, char *src);

// Textures functions in texture.c
void	draw_texture_line(t_screen *screen, t_object *wall);

// Ray functions in raycasting files
void		init_ray(t_ray *ray, t_screen *screen);
void		get_dist_to_vertical_wall(t_map map, t_ray *ray);
void		get_dist_to_horizontal_wall(t_map map, t_ray *ray);
int			check_for_wall(t_map map, t_point point);
double		degree_to_radian(double angle);
int			calculate_distance(t_point player, t_point wall);
void		get_shorter_distance(t_object *distance1, t_object *distance2, t_object *wall);
t_object	*calculate_wall_projection(t_screen *screen, t_ray *ray);

// Sprites
void	get_sprites(t_screen *screen, t_list **objects);

// Ceiling and floor
void	draw_ceiling(t_screen *screen);
void	draw_floor(t_screen *screen);

//color handling
unsigned int	get_rgb_code(int alpha, int red, int green, int blue);
int				get_red(unsigned int rgba);
int				get_green(unsigned int rgba);
int				get_alpha(unsigned int rgba);
int				get_blue(unsigned int rgba);

// Image processing functions
t_image	create_image(t_screen *screen, int width, int height);

// Error functions in error files
void	handle_error(char *message);
#endif
