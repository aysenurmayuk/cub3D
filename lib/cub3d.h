/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:38:42 by amayuk            #+#    #+#             */
/*   Updated: 2025/02/07 13:01:54 by amayuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "GNL/get_next_line.h"

# define SCREEN_W 1920
# define SCREEN_H 1080

typedef struct s_parse
{
	int	c;
	int	f;
	int	no;
	int	so;
	int	we;
	int	ea;
}	t_parse;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_map
{
	char	**map;
	char	**cpymap;
	int		row;
	int		player_count;
}	t_map;

typedef struct s_textures
{
	char	**floor;
	char	**ceiling;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_textures;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*img;
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
	int		*addr;
	int		*addr_n;
	int		*addr_s;
	int		*addr_e;
	int		*addr_w;
	int		bpp;
	int		size_line;
	int		endian;
	int		size;
	double	turn_speed;
	double	walk_speed;
}	t_game;

typedef struct s_raycast
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		wall_start;
	int		wall_end;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	wall_dist;
	double	hit_x;
	double	per_pix;
	int		tex_x;
	int		tex_y;
	double	tex_y_next;
}	t_raycast;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			esc;
	int			left;
	int			right;
}				t_keys;

typedef struct s_data
{
	t_parse		*parse;
	t_textures	*texture;
	t_player	*player;
	t_map		*map;
	t_game		*game;
	t_raycast	*raycast;
	t_keys		*key;
}	t_data;

void	init_parse(t_data *data);
void	init_texture(t_data *data);
void	init_map(t_data *data);
void	init_key(t_data *data);
void	init_game(t_data *data);

void	textures_check(char *av, t_data *data);
void	textures_check_2(char *av, t_data *data, int fd);
int		text_check(char	*str);
int		xpm_check(char *str, t_data *data);
int		color_line_check(char *str, t_data *data);
void	map_check(char *av, t_data *data, char *line, char *trimmed);
int		check_c(char *line);
void	char_check(t_data *data);
void	around_check(t_data *data, int i, int j, int flag);
void	player_around_check(t_data *data, int i, int j);
void	check_all_field(t_data *data, int i);
void	flood_fill(int x, int y, t_data *data);
void	flood_fill_check(t_data *data);
void	is_map_closed(t_data *data);
void	first_last_line(t_data *data);
void	above_space(t_data *data, int map_row);
void	under_space(t_data *data, int i, int row);
void	right_space(t_data *data, int i);
void	left_space(t_data *data, int i);

void	game(t_data *data);
int		put_image(t_data *data);
int		key_press(int key_code, t_data *data);
int		key_release(int key, t_data *data);
void	set_variable(t_data *data, int i);
void	calculate_step(t_data *data);
int		dda_algorithm(t_data *data);
void	set_pixel(t_data *data, int line_h, int side);
void	put_col(t_data *data, int col, int side);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	look_right(t_data *data);
void	look_left(t_data *data);

void	ft_malloc_error(char *msg, t_data *data);
void	ft_texture_error(char *msg, t_data *data);
void	ft_texture_error(char *msg, t_data *data);
void	ft_error(char *msg, t_data *data);
void	destroy_mlx(t_data *data);
void	ft_full_free(t_data *data);
void	double_free(char **str);
void	finish_gnl(int fd);
int		free_rgb(char **rgb_i, char *msg, t_data *data);

#endif