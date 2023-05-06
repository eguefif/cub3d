NAME = test
CFLAGS = -Wextra -Wall -Werror
LIB = -L../libft_full -lft_full
CC = gcc
RM = rm -f

_SRC = test_parsing_scene.c 
_OBJ = $(_SRC:.c=.o)
_INC = cub3d.h parsing.h
SDIR = ./src/
ODIR = ./obj/
IDIR = -I../include -I../libft_full/include
OBJ = $(addprefix $(ODIR), $(_OBJ))
CUB3D_OBJ = $(addprefix $(CODIR), $(_COBJ))
SRC = $(addprefix $(SDIR), $(_SRC))
INC = $(addprefix $(IDIR), $(_INC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(CUB3D_OBJ) $(LIB) -o $@

$(ODIR)%.o: $(SDIR)%.c 
	$(CC) $(CFLAGS) $(IDIR) -c $< -o $@

.PHONY: clean fclean re
clean:
	$(RM) ODIR/*.o

fclean:
	$(RM) cub3d

re: fclean clean all

norme:
	norminette $(SRC) include/cub3d.h
