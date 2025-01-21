NAME = cub3d
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLXFLAGS = #-L./lib/mlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

LIBFT = lib/libft/libft.a
LIBSRC = lib/libft/ft_atoi.c lib/libft/ft_bzero.c lib/libft/ft_calloc.c lib/libft/ft_isalnum.c \
         lib/libft/ft_isalpha.c lib/libft/ft_isascii.c lib/libft/ft_isdigit.c lib/libft/ft_isprint.c \
         lib/libft/ft_itoa.c lib/libft/ft_memchr.c lib/libft/ft_memcmp.c lib/libft/ft_memcpy.c \
         lib/libft/ft_memmove.c lib/libft/ft_memset.c lib/libft/ft_putchar_fd.c lib/libft/ft_putendl_fd.c \
         lib/libft/ft_putnbr_fd.c lib/libft/ft_putstr_fd.c lib/libft/ft_split.c lib/libft/ft_strchr.c \
         lib/libft/ft_strdup.c lib/libft/ft_striteri.c lib/libft/ft_strjoin.c lib/libft/ft_strlcat.c \
         lib/libft/ft_strlcpy.c lib/libft/ft_strlen.c lib/libft/ft_strmapi.c lib/libft/ft_strncmp.c \
         lib/libft/ft_strnstr.c lib/libft/ft_strrchr.c lib/libft/ft_strtrim.c lib/libft/ft_substr.c \
         lib/libft/ft_toupper.c lib/libft/ft_tolower.c

C_SRC = lib/GNL/get_next_line.c src/cub3d.c src/textures_control.c src/textures_control_2.c \
        src/read_map.c src/flood_fill.c src/map_control_3.c utils/init.c utils/free.c utils/error.c

SRCS = $(LIBSRC) $(C_SRC)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLXFLAGS)

$(LIBFT):
	make -C lib/libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C lib/libft clean

fclean: clean
	rm -f $(NAME)
	make -C lib/libft fclean

re: fclean all

.PHONY: all clean fclean re
