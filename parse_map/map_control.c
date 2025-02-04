/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:58:10 by kgulfida          #+#    #+#             */
/*   Updated: 2025/02/04 19:02:03 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	first_last_line(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[0][i])
	{
		if (data->map->map[0][i] != '1' && data->map->map[0][i] != '\n'
			&& data->map->map[0][i] != ' ' && data->map->map[0][i] != '\t')
			ft_error("Error:\nThe map error.\n", data);
		i++;
	}
	i = 0;
	while (data->map->map[data->map->row - 1][i])
	{
		if (data->map->map[data->map->row - 1][i] != '1'
			&& data->map->map[data->map->row - 1][i] != '\n'
			&& data->map->map[data->map->row - 1][i] != ' '
			&& data->map->map[data->map->row - 1][i] != '\t'
			&& data->map->map[data->map->row - 1][i] != '\0')
			ft_error("Error:\nThe map error.\n", data);
		i++;
	}
}

void	above_space(t_data *data, int map_row)
{
	int	j;
	int	control;

	while (map_row-- > 0)
	{
		j = 0;
		while (data->map->map[map_row][j])
		{
			if (data->map->map[map_row][j] == ' ')
			{
				control = map_row - 1;
				while (control > 0 && data->map->map[control][j]
					&& data->map->map[control][j] == ' ')
					control--;
				if (control <= 0 || control == map_row - 1)
				{
					j++;
					continue ;
				}
				else if (data->map->map[control][j] != '1')
					ft_error("Error:\nThe map error.1\n", data);
			}
			j++;
		}
	}
}

void	under_space(t_data *data, int i)
{
	int	j;
	int	control;

	while (++i < data->map->row)
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == ' ')
			{
				control = i + 1;
				while (control < data->map->row && data->map->map[control][j]
					&& data->map->map[control][j] == ' ')
					control++;
				if (control >= data->map->row || control == i + 1)
				{
					j++;
					continue ;
				}
				else if (data->map->map[control][j] != '1')
					ft_error("Error:\nThe map error.2\n", data);
			}
			j++;
		}
	}
}

void	right_space(t_data *data, int i)
{
	int	control;
	int	j;

	while (++i < data->map->row)
	{
		j = 0;
		while (data->map->map[i][j++])
		{
			if (data->map->map[i][j] == ' ')
			{
				control = j + 1;
				while (control < (int)ft_strlen(data->map->map[i])
					&& data->map->map[i][control]
					&& data->map->map[i][control] == ' ')
					control++;
				if (control >= (int)ft_strlen(data->map->map[i]) || control + 1 == (int)ft_strlen(data->map->map[i]))
				{
					j++;
					continue ;
				}
				else if (data->map->map[i][control] != '1')
					ft_error("Error:\nThe map error.3\n", data);
			}
		}
	}
}

void	left_space(t_data *data, int i)
{
	int	j;
	int	control;

	while (++i < data->map->row)
	{
		j = (int)ft_strlen(data->map->map[i]) - 1;
		while (j > 0 && data->map->map[i][j])
		{
			if (data->map->map[i][j] == ' ')
			{
				control = j - 1;
				while (control > 0 && data->map->map[i][control]
					&& data->map->map[i][control] == ' ')
					control--;
				if (control <= 0 || control == j - 1)
				{
					j--;
					continue ;
				}
				else if (data->map->map[i][control] != '1')
					ft_error("Error:\nThe map error.4\n", data);
			}
			j--;
		}
	}
}
