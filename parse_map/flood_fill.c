/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:08:55 by kgulfida          #+#    #+#             */
/*   Updated: 2025/02/04 18:42:10 by kgulfida         ###   ########.fr       */
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

void	around_check(t_data *data, int i, int j)
{
	int		flag;
	char	a;
	char	b;
	char	c;
	char	d;

	flag = 0;
	a = data->map->map[i - 1][j];
	b = data->map->map[i + 1][j];
	c = data->map->map[i][j - 1];
	d = data->map->map[i][j + 1];
	if (data->map->map[i - 1] && a && (a == '0' || a == '1' || a == 'S' || a == 'E' || a == 'N' || a == 'W'))
		flag++;
	if (data->map->map[i + 1] && b && (b == '0' || b == '1' || b == 'S' || b == 'N' || b == 'E' || b == 'W'))
		flag++;
	if(c && (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W' || c == 'E'))
		flag++;
	if(d && (d == '0' || d == '1' || d == 'N' || d == 'W' || d == 'S' || d == 'E'))
		flag++;
	if (flag < 4)
		ft_error("Error\nThe map error.\n", data);
}

void	check_all_field(t_data *data, int i)
{
	int	j;

	while (++i < data->map->row)
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == '0')
				around_check(data, i, j);
			j++;
		}
	}
}

void	is_map_closed(t_data *data)
{
	first_last_line(data);
	under_space(data, -1);
	above_space(data, (data->map->row - 1));
	left_space(data, -1);
	right_space(data, -1);
	check_all_field(data, -1);
}
