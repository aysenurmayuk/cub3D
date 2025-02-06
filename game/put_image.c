/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:13:48 by kgulfida          #+#    #+#             */
/*   Updated: 2025/02/06 12:13:49 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

static int	set_color(char **str)
{
	int	i;
	int	rgb[3];
	int	color;

	i = 0;
	while (i < 3)
	{
		rgb[i] = ft_atoi(str[i]);
		i++;
	}
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (color);
}

static void	put_rgb(t_data *data)
{
	int	i;
	int	j;
	int	sky_color;
	int	surface_color;

	sky_color = set_color(data->texture->ceiling);
	surface_color = set_color(data->texture->floor);
	i = 0;
	while (i < screen_h)
	{
		j = 0;
		while (j < screen_w)
		{
			if (i < screen_h / 2)
				data->game->addr[i * screen_w + j] = sky_color;
			else
				data->game->addr[i * screen_w + j] = surface_color;
			j++;
		}
		i++;
	}
}

void	calculate_rays(t_data *data, int i, int side, int line_h)
{
	while (i < screen_w)
	{
		set_variable(data, i);
		calculate_step(data);
		side = dda_algorithm(data);
		if (side == 0)
			data->raycast->wall_dist = data->raycast->side_x
				- data->raycast->delta_x;
		else
			data->raycast->wall_dist = data->raycast->side_y
				- data->raycast->delta_y;
		line_h = (int)(screen_h / data->raycast->wall_dist);
		data->raycast->wall_start = -line_h / 2 + screen_h / 2;
		if (data->raycast->wall_start < 0)
			data->raycast->wall_start = 0;
		data->raycast->wall_end = line_h / 2 + screen_h / 2;
		if (data->raycast->wall_end > screen_h)
			data->raycast->wall_end = screen_h;
		set_pixel(data, line_h, side);
		put_col(data, i, side);
		i++;
	}
}

void	move_player(t_data *data)
{
	if (data->key->w)
		move_up(data);
	if (data->key->s)
		move_down(data);
	if (data->key->a)
		move_left(data);
	if (data->key->d)
		move_right(data);
	if (data->key->right)
		look_right(data);
	if (data->key->left)
		look_left(data);
}

int	put_image(t_data *data)
{
	mlx_clear_window(data->game->mlx, data->game->window);
	put_rgb(data);
	calculate_rays(data, 0, 0, 0);
	mlx_put_image_to_window(data->game->mlx, data->game->window,
		data->game->img, 0, 0);
	move_player(data);
	return (0);
}
