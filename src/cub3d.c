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

int main(int ac, char **av)
{
    (void)av;
    // void *mlx;
    // void *win;
    if(ac != 2)
        ft_error("Error: number of invalid argument");

    map_check(av[1]);
    // mlx = mlx_init();
    // if (!mlx)
    //     return (1);

    // win = mlx_new_window(mlx, 800, 600, "Cub3D");
    // if (!win)
    //     return (1);

    // mlx_loop(mlx);
    return (0);
}