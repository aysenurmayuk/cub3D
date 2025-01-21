/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:08:55 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/20 15:22:01 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	flood_fill_check(t_cubdata *cubdata)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cubdata->map->row)
	{
		j = 0;
		while (cubdata->map->cpymap[i][j])
		{
			if (cubdata->map->cpymap[i][j] != ' ' && cubdata->map->cpymap[i][j] != 'F'
				&& cubdata->map->cpymap[i][j] != '\n')
				ft_error("Error\nMultiple map.");
			j++;
		}
	}
}

void	flood_fill(int x, int y, t_cubdata *cubdata)
{
	if (x < 0 || y < 0 || x >= cubdata->map->row
		|| y >= (int)ft_strlen(cubdata->map->cpymap[x])
		|| cubdata->map->cpymap[x][y] == ' ' || cubdata->map->cpymap[x][y] == 'F')
		return ;
	cubdata->map->cpymap[x][y] = 'F';
	flood_fill(x + 1, y, cubdata);
	flood_fill(x - 1, y, cubdata);
	flood_fill(x, y + 1, cubdata);
	flood_fill(x, y - 1, cubdata);
}

void	find_player(t_cubdata *cubdata)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cubdata->map->row)
	{
		j = -1;
		while (cubdata->map->map[i][++j])
		{
			if (cubdata->map->map[i][j] == 'N' || cubdata->map->map[i][j] == 'W'
				|| cubdata->map->map[i][j] == 'S' || cubdata->map->map[i][j] == 'E')
			{
				cubdata->player->loc_x = i;
				cubdata->player->loc_y = j;
			}
		}
	}
	flood_fill(cubdata->player->loc_x, cubdata->player->loc_y, cubdata);
}

void	player_check(t_cubdata *cubdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < cubdata->map->row)
	{
		j = 0;
		while (cubdata->map->map[i][j])
		{
			if (cubdata->map->map[i][j] == 'N' || cubdata->map->map[i][j] == 'S'
				|| cubdata->map->map[i][j] == 'W' || cubdata->map->map[i][j] == 'E')
				cubdata->map->player_count++;
			j++;
		}
		i++;
	}
	if (cubdata->map->player_count != 1)
		ft_error("Error:\nThe unacceptable number of player.");
	find_player(cubdata);
}

void	char_check(t_cubdata *cubdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < cubdata->map->row)
	{
		j = 0;
		while (cubdata->map->map[i][j])
		{
			if (cubdata->map->map[i][j] != '1' && cubdata->map->map[i][j] != '0'
				&& cubdata->map->map[i][j] != 'N' && cubdata->map->map[i][j] != 'S'
				&& cubdata->map->map[i][j] != 'W' && cubdata->map->map[i][j] != 'E'
				&& cubdata->map->map[i][j] != ' ' && cubdata->map->map[i][j] != '\n')
				ft_error("Error:\nThe map has invalid charecter.");
			j++;
		}
		i++;
	}
	player_check(cubdata);
}

