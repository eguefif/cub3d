#Variables
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wextra -Werror -Wall -I
AR = ar -rcs

# Colors
Y=\033[0;34m
B=\033[0;34m
NOCOLOR=\33[0m

# Path and sources
_SRC = ft_printf.c utils.c parsing.c parsing_utils.c make_cs.c address_strbuilder.c\
	   basic_str_builder.c csstring_builder.c csstring_builder_utils.c finalstr_builder.c
_OBJ = $(_SRC:.c=.o)
_DEPS = ft_printf.h
IDIR = ./include
ODIR = ./src/obj/
SDIR = ./src/
SRC = $(addprefix $(SDIR),$(_SRC))
OBJ = $(addprefix $(ODIR),$(_OBJ))
DEPS = $(addprefix $(IDIR)/,$(_DEPS))

# Target and rules
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

oonly: $(OBJ)

$(ODIR)%.o: $(SDIR)%.c $(IDIR)/ft_printf.h
	$(CC) $(CFLAGS)$(IDIR) -c -o $@ $<

# Phony target
.PHONY: all clean fclean re norme

norme:
	norminette $(SRC) $(DEPS)

clean:
	rm -rf $(ODIR)/*.o
	rm -rf $(OLFTDIR)/*.o

fclean:
	rm -f $(NAME)

re: clean fclean all
