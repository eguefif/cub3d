NAME = libperso.a
CC = gcc
CFLAGS = -Wextra -Werror -Wall -I
AR = ar -rcs

Y=\033[0;34m
B=\033[0;34m
NOCOLOR=\33[0m

LIBFTO=./libft/src/obj
FTPRINTFO=./ft_printf/src/obj
GETNLO=get_next_line/src/obj/
ODIR=./obj

all: $(NAME)

$(NAME): 
	cp $(LIBFTO)/*.o $(ODIR)
	cp $(FTPRINTFO)/*.o $(ODIR)
	cp $(GETNLO)/*.o $(ODIR)
	$(AR) $@ $(ODIR)/*.o 


.PHONY: all clean fclean re norme

norme:
	norminette $(SRC) $(DEPS)

clean:
	rm -rf $(ODIR)/*.o

fclean:
	rm -f $(NAME)

re: clean fclean all
