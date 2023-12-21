CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = miniRT

HDR_DIR = ./include/
HDR = \
	$(HDR_DIR)minirt.h \
	$(HDR_DIR)parsing.h \
	$(HDR_DIR)minilibx.h \
	$(HDR_DIR)element.h \
	$(HDR_DIR)error.h \
	$(HDR_DIR)hittable.h \
	$(HDR_DIR)world.h \
	$(HDR_DIR)shading.h

SRCS = \
	./src/main.c \
	./src/rendering.c \
	./src/shading/phong_lighting.c \
	./src/shading/constructor.c \
	./src/shading/diffuse.c \
	./src/shading/specular.c \
	./src/minilibx/init.c \
	./src/minilibx/hook.c \
	./src/parsing/parse.c \
	./src/parsing/get_functions.c \
	./src/parsing/get_id.c \
	./src/parsing/get_object.c \
	./src/parsing/utils/get_next_line.c \
	./src/parsing/utils/get_next_line_utils.c \
	./src/parsing/utils/ft_split.c \
	./src/parsing/utils/ft_functions.c \
	./src/parsing/utils/ft_functions2.c \
	./src/error/error.c \
	./src/world/element/color.c \
	./src/world/element/vector/vector.c \
	./src/world/element/vector/util.c \
	./src/world/element/pixel.c \
	./src/world/element/ray.c \
	./src/world/hittable/hit.c \
	./src/world/hittable/test.c \
	./src/world/hittable/plane.c \
	./src/world/hittable/cylinder.c \
	./src/world/hittable/sphere.c \
	./src/world/world.c \
	./src/world/light.c \
	./src/world/ambient.c \
	./src/world/view.c

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
