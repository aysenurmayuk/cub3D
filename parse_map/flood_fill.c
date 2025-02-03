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

void	flood_fill_check(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->row)
	{
		j = 0;
		while (data->map->cpymap[i][j])
		{
			if (data->map->cpymap[i][j] != ' ' && data->map->cpymap[i][j] != 'F'
				&& data->map->cpymap[i][j] != '\n')
				ft_error("Error\nMultiple map.\n", data);
			j++;
		}
	}
}

void	flood_fill(int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || y >= data->map->row
		|| x >= (int)ft_strlen(data->map->cpymap[y])
		|| data->map->cpymap[y][x] == ' ' || data->map->cpymap[y][x] == 'F')
		return ;
	data->map->cpymap[y][x] = 'F';
	flood_fill(x + 1, y, data);
	flood_fill(x - 1, y, data);
	flood_fill(x, y + 1, data);
	flood_fill(x, y - 1, data);
}

void	is_map_closed(t_data *data)
{
	first_last_line(data);
	under_space(data, -1);
	above_space(data, (data->map->row - 1));
	left_space(data, -1);
	right_space(data, -1);
}
