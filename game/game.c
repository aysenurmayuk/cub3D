/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:23:31 by amayuk            #+#    #+#             */
/*   Updated: 2025/01/21 19:12:15 by amayuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void game(t_cubdata *cubdata)
{
    cubdata->mlx->mlx = mlx_init();
	if (!cubdata->mlx->mlx)
		ft_error("Error\n MiniLibX initialization failed");
	cubdata->mlx->window = mlx_new_window(cubdata->mlx->mlx, 800, 600, "Cub3D");
	if (!cubdata->mlx->window)
		ft_error("Error\n Window creation failed");
	mlx_loop(cubdata->mlx->mlx);
}