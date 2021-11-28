CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	fractol
I_DIR	=	include
L_DIR	=	lib
LIB		=	-lmlx -lft

SRC		=	src/main.c	\
			src/set.c	\
			src/utils.c		\
			src/hoooookit.c \
			src/draw.c		

OBJ		=	$(SRC:%.c=%.o)

all: include/fractol.h $(NAME)

$(NAME): $(OBJ) 
	$(CC) -o $(NAME) $(OBJ) -I$(I_DIR) -L$(L_DIR) $(LIB) -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -o $@ -c $< -I$(I_DIR)

run: all
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm  -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re