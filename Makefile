NAME = cub3d
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = #-L./lib/mlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

SRCS = src/cub3d.c src/error.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re