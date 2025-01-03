#ifndef CUB3D_H
# define CUB3D_H
//# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
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
    int     map_width;
    int     map_height;
    int     space_count;
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

void    ft_error(char *msg);
void    ft_free(t_cubdata *cubdata);
void    argv_check(char *argv);
void    textures_check(char *argv, t_cubdata *cubdata);

#endif