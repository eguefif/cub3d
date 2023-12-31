# Variables
NAME = libft.a
ODIR = ./src/obj/
SDIR = ./src/
CC = gcc
INCLUDE = ../include
CFLAGS = -Wextra -Werror -Wall -I
AR = ar -rcs

# Sources
_SRC = ft_pow.c ft_memset.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_putchar.c ft_putstr.c \
	  ft_itoa.c ft_atoi.c ft_strlen.c ft_putnbr.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c \
	  ft_putendl_fd.c ft_toupper.c ft_tolower.c ft_isprint.c ft_isascii.c ft_strdup.c ft_strcpy.c \
	  ft_strncpy.c  ft_strcmp.c ft_strncmp.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memcmp.c \
	  ft_memchr.c ft_memmove.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_pow.c ft_btoa.c ft_putendl.c 
_OBJ = $(_SRC:.c=.o)
_OBJD = $(_SRC:.c=_d.o)
OBJD = $(addprefix $(ODIR),$(_OBJD))
OBJ = $(addprefix $(ODIR),$(_OBJ))
SRC = $(addprefix $(SDIR),$(_SRC))

# Targets
all:	$(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^
	echo "$(NAME) created."

oonly: $(OBJ)
	echo "Compiled every .c in $(ODIR)"

$(ODIR)%.o: $(SDIR)%.c $(INCLUDE)/libft.h
	$(CC) $(CFLAGS)$(INCLUDE) -c -o $@ $<

$(ODIR)%_d.o: $(SDIR)%.c $(INCLUDE)/libft.h
	$(CC) $(CFLAGS)$(INCLUDE) -c -fPIC $@ $<

# Phony
.PHONY: fclean clean re norme
fclean:
	rm -f libft.a

clean:
	rm -f $(ODIR)*.o 

re: clean fclean all clean

norme:
	norminette $(SRC)
