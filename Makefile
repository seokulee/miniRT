CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = miniRT

HDR_DIR = ./include/
HDR = \
	$(HDR_DIR)minirt.h \
	$(HDR_DIR)minilibx.h

SRCS = \
	./src/main.c \
	./src/minilibx/init.c \
	./src/minilibx/hook.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = ./mlx/
MLX = $(MLX_DIR)libmlx.a

LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

INCLUDE = -I$(MLX_DIR) -I$(HDR_DIR)

all : $(NAME)

$(NAME) : $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIB) $^ -o $(NAME)

$(MLX) :
	make -C $(MLX_DIR)

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	make clean
	make clean -C $(MLX_DIR)
	rm -f $(NAME)

re :
	make clean
	rm -f $(NAME)
	make all

.PHONY : all clean fclean re