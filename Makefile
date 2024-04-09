NAME = so_long
MLX_DIR = minilibx-linux/
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
RM = rm -f

SRCS = main.c \
	check_errors.c \
	controls.c \
	images.c \
	map_utils.c \
	wall_check.c \
	printf.c \
	render_wd.c \
	create.c

OBJS = $(SRCS:.c=.o)

GNL = ./get_next_line/get_next_line.c \
	./get_next_line/get_next_line_utils.c

GNL_OBJS = $(GNL:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(GNL_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
