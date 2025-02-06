/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:13:54 by kgulfida          #+#    #+#             */
/*   Updated: 2025/02/06 12:13:55 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	look_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player->dir_x;
	data->player->dir_x = data->player->dir_x * cos(-data->game->turn_speed)
		- data->player->dir_y * sin(-data->game->turn_speed);
	data->player->dir_y = old_dir_x * sin(-data->game->turn_speed)
		+ data->player->dir_y * cos(-data->game->turn_speed);
	old_plane_x = data->player->plane_x;
	data->player->plane_x = data->player->plane_x * cos(-data->game->turn_speed)
		- data->player->plane_y * sin(-data->game->turn_speed);
	data->player->plane_y = old_plane_x * sin(-data->game->turn_speed)
		+ data->player->plane_y * cos(-data->game->turn_speed);
}

void	look_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player->dir_x;
	data->player->dir_x = data->player->dir_x * cos(data->game->turn_speed)
		- data->player->dir_y * sin(data->game->turn_speed);
	data->player->dir_y = old_dir_x * sin(data->game->turn_speed)
		+ data->player->dir_y * cos(data->game->turn_speed);
	old_plane_x = data->player->plane_x;
	data->player->plane_x = data->player->plane_x * cos(data->game->turn_speed)
		- data->player->plane_y * sin(data->game->turn_speed);
	data->player->plane_y = old_plane_x * sin(data->game->turn_speed)
		+ data->player->plane_y * cos(data->game->turn_speed);
}
