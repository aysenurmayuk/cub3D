/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:23:31 by amayuk            #+#    #+#             */
/*   Updated: 2025/02/06 15:39:53 by amayuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	set_address(t_data *data)
{
	data->game->addr_n = (int *)mlx_get_data_addr(data->game->no,
			&data->game->bpp, &data->game->size_line, &data->game->endian);
	data->game->addr_s = (int *)mlx_get_data_addr(data->game->so,
			&data->game->bpp, &data->game->size_line, &data->game->endian);
	data->game->addr_e = (int *)mlx_get_data_addr(data->game->ea,
			&data->game->bpp, &data->game->size_line, &data->game->endian);
	data->game->addr_w = (int *)mlx_get_data_addr(data->game->we,
			&data->game->bpp, &data->game->size_line, &data->game->endian);
	if (!data->game->addr_e || !data->game->addr_w || !data->game->addr_s
		|| !data->game->addr_n)
		ft_error("Error:\nTextures' address creation failed.\n", data);
}

void	open_window(t_data *data)
{
	data->game->mlx = mlx_init();
	data->game->window = mlx_new_window(data->game->mlx, SCREEN_W, SCREEN_H,
			"Cub3D");
	data->game->img = mlx_new_image(data->game->mlx, SCREEN_W, SCREEN_H);
	data->game->addr = (int *)mlx_get_data_addr(data->game->img,
			&data->game->bpp, &data->game->size_line, &data->game->endian);
	if (!data->game->mlx || !data->game->window || !data->game->img
		|| !data->game->addr)
		ft_error("Error\nGame creation failed.\n", data);
	data->game->no = mlx_xpm_file_to_image(data->game->mlx,
			data->texture->north, &data->game->size, &data->game->size);
	data->game->so = mlx_xpm_file_to_image(data->game->mlx,
			data->texture->south, &data->game->size, &data->game->size);
	data->game->we = mlx_xpm_file_to_image(data->game->mlx, data->texture->west,
			&data->game->size, &data->game->size);
	data->game->ea = mlx_xpm_file_to_image(data->game->mlx, data->texture->east,
			&data->game->size, &data->game->size);
	if (!data->game->no || !data->game->so || !data->game->ea
		|| !data->game->we)
		ft_error("Error:\nMissing image file or texture creation faild.", data);
	set_address(data);
}

int	close_window(t_data *data)
{
	printf("Game closed.\n");
	destroy_mlx(data);
	exit(0);
}

void	game(t_data *data)
{
	open_window(data);
	mlx_loop_hook(data->game->mlx, put_image, data);
	mlx_hook(data->game->window, 2, 1L << 0, key_press, data);
	mlx_hook(data->game->window, 3, 1L << 1, key_release, data);
	mlx_hook(data->game->window, 17, 0, close_window, data);
	mlx_loop(data->game->mlx);
}
