NAME = fract-ol
MINILBX = minilibx
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	src/main.c \
		src/render.c \
		src/hooks.c \
		src/fractals.c \
		src/utils.c \
		src/colors.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MINILBX)
	$(CC) $(CFLAGS) $(OBJ) -L$(MINILBX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c includes/fractol.h
	$(CC) $(CFLAGS) -I$(MINILBX) -Iincludes -c $< -o $@

clean:
	make -C $(MINILBX) clean
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re