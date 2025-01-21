#ifndef CUB3D_H
# define CUB3D_H
# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "GNL/get_next_line.h"

typedef struct s_parse
{
    int c;
    int f;
    int no;
    int so;
    int we;
    int ea;
}   t_parse;

typedef struct s_player
{
    double  loc_x;
    double  loc_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
}   t_player;

typedef struct s_map
{
    char    **map;
    char    **cpymap;
    int     row;
	int		player_count;
}   t_map;

typedef struct s_textures
{
   char **floor;
   char **ceiling;
   char *north;
   char *south;
   char *west;
   char *east;
}   t_textures;

typedef struct s_mlx
{
   void *mlx;
   void *window;
}   t_mlx;

typedef struct s_cubdata
{
    t_mlx       *mlx;
    t_map       *map;
    t_textures  *textture;
    t_player    *player;
    t_parse     *parse;
}   t_cubdata;

void    init_parse(t_cubdata *cubdata);
void    init_texture(t_cubdata *cubdata);
void    init_map(t_cubdata *cubdata);
void    init_game(t_cubdata *cubdata);

void    textures_check(char *av, t_cubdata *cubdata);
void    xpm_extension_check(char *texture);
void    color_line_check(char *str, t_cubdata *cubdata, int i);
void	map_check(char *av, t_cubdata *cubdata, char *line, char *trimmed);
void	char_check(t_cubdata *cubdata);
void	flood_fill_check(t_cubdata *cubdata);
void	is_map_closed(t_cubdata *cubdata);

void    ft_error(char *msg);
void    ft_free(t_cubdata *cubdata);
void    double_free(char **str);


void    game(t_cubdata *cubdata);

#endif