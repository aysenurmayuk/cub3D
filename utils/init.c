/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:50:33 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/21 18:50:06 by amayuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	init_parse(t_data *data)
{
	data->parse->c = 0;
	data->parse->f = 0;
	data->parse->no = 0;
	data->parse->so = 0;
	data->parse->ea = 0;
	data->parse->we = 0;
}

void	init_texture(t_data *data)
{
	data->texture->ceiling = NULL;
	data->texture->floor = NULL;
	data->texture->north = NULL;
	data->texture->south = NULL;
	data->texture->west = NULL;
	data->texture->east = NULL;
	data->map->cpymap = NULL;
	data->map->map = NULL;
	data->map->row = 0;
	data->map->player_count = 0;
}

void	init_map(t_data *data)
{
	data->map->map = (char **)malloc(data->map->row * sizeof(char *));
	data->map->cpymap = (char **)malloc(data->map->row * sizeof(char *));
	if (data->map->map == NULL || data->map->cpymap == NULL)
		ft_error("Error:\nMemory problem!");
}

void	init_game(t_data *data)
{
	data->game->mlx = NULL;
	data->game->window = NULL;
	data->game->img = NULL;
	data->game->no = NULL;
	data->game->so = NULL;
	data->game->ea = NULL;
	data->game->we = NULL;
	data->game->addr = NULL;
	data->game->addr_n = NULL;
	data->game->addr_s = NULL;
	data->game->addr_e = NULL;
	data->game->addr_w = NULL;
	data->game->size = 0;
	data->game->turn_speed = 0.03;
	data->game->walk_speed = 0.032;
}

void	init_key(t_data *data)
{
	data->key->w = 0;
	data->key->a = 0;
	data->key->s = 0;
	data->key->d = 0;
	data->key->left = 0;
	data->key->right = 0;
}
