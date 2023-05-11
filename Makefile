NAME = cub3d
CFLAGS = -Wextra -Wall -Werror
LIB = -L./libft_full -lft_full -L~/coding/c/minilibx-linux -lmlx \
	  -L/usr/X11/lib -lX11 -lXext -lm -lz
CC = gcc
RM = rm -f
DEBUG = -g -ggdb3

_SRC = cub3d.c \
	   error_management.c \
	   development_tools.c \
	   parsing.c \
	   parsing_type_identifier.c \
	   parsing_map.c \
	   parsing_is_types.c \
	   parsing_map_information.c \
	   init_ray_casting.c \
	   check_map.c \
	   check_map_rectangle.c \
	   init_game.c \
	   terminate.c \
	   keyboard_manager.c \
	   rendering.c \
	   rendering_utils.c \
	   draw_basic_figures.c \
	   buffering.c \
	   raycasting.c \
	   raycasting_utils.c \
	   2d_model.c \
	   player_movement.c \
	   time_handler.c \
	   init_textures.c
_OBJ = $(_SRC:.c=.o)
_INC = cub3d.h parsing.h
SDIR = ./src/
ODIR = ./obj/
IDIR = -I./include -I./libft_full/include -I/usr/include
OBJ = $(addprefix $(ODIR), $(_OBJ))
SRC = $(addprefix $(SDIR), $(_SRC))
INC = $(addprefix $(IDIR), $(_INC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIB) -o $@

$(ODIR)%.o: $(SDIR)%.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -o $@

.PHONY: clean fclean re
clean:
	$(RM) $(ODIR)*.o

fclean:
	$(RM) cub3d

re: fclean clean all

norme:
	norminette $(SRC) include/cub3d.h include/parsing.h
