/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysenurmayuk <aysenurmayuk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:46 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/02 13:39:29 by aysenurmayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void    init_data(t_cubdata *cubdata)
{
    cubdata->parse->c = 0;
    cubdata->parse->f = 0;
    cubdata->parse->no = 0;
    cubdata->parse->so = 0;
    cubdata->parse->ea = 0;
    cubdata->parse->we = 0;
}

void    init_cubdata(t_cubdata *cubdata)
{
    cubdata->map = malloc(sizeof(t_map));
    cubdata->mlx = malloc(sizeof(t_mlx));
    cubdata->parse = malloc(sizeof(t_parse));
    cubdata->player = malloc(sizeof(t_player));
    cubdata->textture = malloc(sizeof(t_textures));
    init_data(cubdata);
}

int main(int ac, char **av)
{
    t_cubdata   *cubdata;

    if(ac != 2)
        ft_error("Error: number of invalid argument");
    argv_check(av[1]);
    cubdata = malloc(sizeof(t_cubdata));
    if (!cubdata)
        ft_error("Error: malloc problem");
    init_cubdata(cubdata);
    textures_check(av[1], cubdata);
    // mlx = mlx_init();
    // if (!mlx)
    //     return (1);

    // win = mlx_new_window(mlx, 800, 600, "Cub3D");
    // if (!win)
    //     return (1);

    // mlx_loop(mlx);
    return (0);
}