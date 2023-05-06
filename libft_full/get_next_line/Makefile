NAME=libget_next_line.a
CC=gcc
RM=rm -f
FLAGS=-Wall -Werror -Wextra -I
BUFFER=-D BUFFER_SIZE=9999
AR=ar -rcs

_SRC = get_next_line.c get_next_line_utils.c
_OBJ=$(_SRC:.c=.o)
_INC=get_next_line.h
SDIR=./src/
ODIR=./src/obj/
IDIR=include/
SRC=$(addprefix $(SDIR),$(_SRC))
OBJ=$(addprefix $(ODIR),$(_OBJ))
INC=$(addprefix $(IDIR),$(_INC))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

$(ODIR)%.o: $(SDIR)%.c $(IDIR)get_next_line.h
	$(CC) $(FLAGS)$(IDIR) $(BUFFER) -c -o $@ $<

oonly: $(OBJ)

.PHONY: clean fclean re norme

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: clean fclean all

norme:
	norminette $(SRC) $(INC)
