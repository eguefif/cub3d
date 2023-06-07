/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguefif <eguefif@fastmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:45:35 by eguefif           #+#    #+#             */
/*   Updated: 2023/06/06 17:24:22 by eguefif          ###   ########.fr       */
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
# define PROJECTION_PLANE_DST 450
# define SQUARE_SIZE 192
# define PLAYER_SIZE 7
# define NBR_TEXTURES 5
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define SKY 4
# define SPEED 5
# define ROT_SPEED 1
# define FPS 30
# define IDLE 0
# define ATTACK 1
# define PAIN 2
# define WALK 3
# define DEATH 4
# define ANIMATION_TIMING 0.05

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

typedef struct s_point
{
	double	x;
	double	y;
	t_color	color;
}			t_point;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}			t_map;

typedef struct s_image
{
	void	*img_ptr;
	char	path[100];
	int		width;
	int		height;
	double	ratio;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*start_area_ptr;
}			t_image;

typedef struct s_sprite
{
	t_point	coord;
	t_image	image;
	double	shift;
}			t_sprite;

typedef struct s_display_info
{
	int		rows;
	int		cols;
	t_image	image;
}				t_display_info;

typedef struct s_item
{
	t_point	coord;
	int		image_number;
}			t_item;

typedef struct s_animation
{
	double		timing;
	char		path[50];
	t_sprite	sprites[10];
	double		shift;
	int			images_nbr;
}				t_animation;

typedef struct s_animated_sprite
{
	t_point		coord;
	int			animation;
	int			current_img_index;
	double		time;
}				t_anim_sprite;

typedef struct s_npc
{
	char		path[100];
	char		name[100];
	t_animation	walk;
	t_animation	idle;
	t_animation	attack;
	t_animation	pain;
	t_animation	death;
}				t_npc;

typedef struct s_npc_instance
{
	t_point		coord;
	int			state;
	int			life;
	int			aim_skill;
	char		type[50];
}				t_npc_instance;

typedef struct s_scene
{
	t_resolution	resolution;
	t_color			floor;
	t_color			ceiling;
	t_color			wall;
	t_map			map;
	t_image			textures[NBR_TEXTURES];
	t_npc_instance	ennemies[50];
	t_item			items[50];
	t_sprite		sprites[50];
	t_npc			npc[50];
	t_animation		animations[50];
	t_anim_sprite	anim_sprites[50];	
	int				npc_counter;
	int				npc_instance_counter;
	int				images_sprite_count;
	int				anim_sprite_count;
	int				anim_count;
	int				items_count;
}					t_scene;

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
	double	lateral_movement;
	double	movement;
}			t_player;

typedef struct s_raycasting_parameter
{
	double	field_of_view;
	double	half_fov;
	double	max_ray_nbr;
	double	delta_angle;
	double	projection_var;
	double	scale;
}			t_raycasting_parameter;

typedef struct s_screen
{
	void					*mlx_ptr;
	void					*window;
	double					elapsed;
	t_player				player;
	t_scene					scene;
	t_screen_buffer			buffer;
	t_raycasting_parameter	raycasting_param;
	t_point					mouse;
	int						pause;
}							t_screen;

typedef struct s_object
{
	t_point	coord;
	t_point	buffer_coord;
	char	type;
	double	ray_angle;
	int		texture;
	double	height;
	double	width;
	double	distance;
	double	texture_offset;
	t_point	subsurface;
	double	subsurface_height;
	double	scale_factor;
	double	offset;
	t_image	image;
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
void	init_game(t_screen *screen, char *path);
void	init_color(t_screen *screen);
int		get_color(t_screen *screen, t_color color);
void	init_raycasting(t_screen *screen);
void	init_screen_buffer(t_screen *screen);
void	init_wall_textures(t_screen *screen);
void	init_mouse(t_screen *screen);
void	parsing_map_information(t_screen *screen);
void	looking_for_objects(t_screen *screen);
void	looking_for_animated_sprite(t_screen *screen);
void	looking_for_npc(t_scene *scene);
void	init_animations(t_screen *screen);
void	init_sprites(t_screen *screen);
void	init_npc_animation(t_screen *screen);
int		terminate_game(t_screen *screen);
void	parsing_sprites(t_scene *scene, char **splitted_line);
void	parsing_animations(t_scene *scene, char **splitted_line);
void	parsing_npc(t_scene *scene, char **splitted_line);
void	get_animation(void *mlx, t_animation *animation);

// Main loop function in keyboard_manager.c
// rendering.c and player_movement.c time.c
int		handle_pressedkey(int key, t_screen *screen);
int		handle_releasedkey(int key, t_screen *screen);
int		mouse_manager(int button, int x, int y, t_screen *screen);
int		rendering_game(t_screen *screen);
void	handle_movement(t_screen *screen);
void	check_time(t_screen *screen);
void	mouse_movement(t_screen *screen);

// graphic functions using mlx in buffering.c and draw_basic_figure.
void	swap_frame_screen(t_screen *screen);
void	draw_pixel_on_buffer(t_screen *screen, t_point point);
void	draw_rectangle(t_screen *screen, int width, int height, t_point coord);
int		get_color(t_screen *screen, t_color color);
void	copy_byte_to_image(char *dst, char *src);

// Textures functions in draw_texture.c
void	draw_objects(t_screen *screen, t_object *wall);
void	sort_objects_by_distance(t_list *first, t_list *last);
t_list	*last_node(t_list *head);

// Ray functions in raycasting files
void	init_ray(t_ray *ray, t_screen *screen, double *angle);
void	get_dist_to_vertical_wall(t_map map, t_ray *ray);
void	get_dist_to_horizontal_wall(t_map map, t_ray *ray);
int		check_for_wall(t_map map, t_point point);
int		check_for_collision(t_map map, t_point point);
double	degree_to_radian(double angle);
int		calculate_distance(t_point player, t_point wall);
void	get_shorter_distance(t_object *distance1,
			t_object *distance2, t_object *wall);
void	correct_fishbowl_effect(t_screen *screen, t_object *wall);

t_object	*calculate_wall_projection(t_screen *screen, t_ray *ray);

// Sprites
void	get_sprites(t_screen *screen, t_list **objects);
void	get_animated_sprites(t_screen *screen, t_list **objects);
void	build_sprite_objects(t_screen *screen, t_sprite sprite,
			t_list **objects);
void	update_animated_sprite(t_scene scene, t_anim_sprite *anim_sprite);
void	draw_sprites(t_screen *screen, t_image *src, t_object *object);
void	draw_walls(t_screen *screen, t_image src, t_object *object);
t_sprite	build_animated_sprite(t_screen *screen, t_anim_sprite anim_sprite);
void	update_npc(t_screen *screen, t_list **objects);

// Ceiling and floor
void	draw_ceiling(t_screen *screen);
void	draw_floor(t_screen *screen);

//color handling
unsigned int	get_rgb_code(int alpha, int red, int green, int blue);
int		get_red(unsigned int rgba);
int		get_green(unsigned int rgba);
int		get_alpha(unsigned int rgba);
int		get_blue(unsigned int rgba);

// Image processing functions
t_image	create_image(t_screen *screen, int width, int height);
void	create_image_from_path(void *mlx, t_image *image);

// maths
int		calculate_distance(t_point player, t_point wall);
double	degree_to_radian(double angle);

// Error functions in error files
void	handle_error(char *message);
#endif
