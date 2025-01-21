/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:58:10 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/21 10:54:44 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	first_last_line(t_cubdata *cubdata)
{
	int	i;

	i = 0;
	while (cubdata->map->map[0][i])
	{
		if (cubdata->map->map[0][i] != '1' && cubdata->map->map[0][i] != '\n' 
			&& cubdata->map->map[0][i] != ' ' && cubdata->map->map[0][i] != '\t')
			ft_error("Error:\nThe map is not closed.");
		i++;
	}
	i = 0;
	while (cubdata->map->map[cubdata->map->row-1][i])
	{
		if (cubdata->map->map[cubdata->map->row-1][i] != '1' && cubdata->map->map[cubdata->map->row-1][i] != '\n' 
			&& cubdata->map->map[cubdata->map->row-1][i] != ' ' && cubdata->map->map[cubdata->map->row-1][i] != '\t'
			&& cubdata->map->map[cubdata->map->row-1][i] != '\0')
			ft_error("Error:\nThe map is not closed.");
		i++;
	}
}

void	above_space(t_cubdata *cubdata, int map_row)
{
	int	j;
	int control;

	while (map_row > 0)
	{
		j = 0;
		while (cubdata->map->map[map_row][j])
		{
			if (cubdata->map->map[map_row][j] == ' ')
			{
				control = map_row - 1;
				while (control > 0 && cubdata->map->map[control][j] && cubdata->map->map[control][j] == ' ')
					control--;
				if (control <= 0)
				{
					j++;
					continue;
				}
				else if (cubdata->map->map[control][j] != '1')
					ft_error("Error:\nThe map is not closed.1");
			}
			j++;
		}
		map_row--;
	}
}

void	under_space(t_cubdata *cubdata, int i)
{
	int	j;
	int	control;

	while (i < cubdata->map->row)
	{
		j = 0;
		while (cubdata->map->map[i][j])
		{
			if (cubdata->map->map[i][j] == ' ')
			{
				control = i + 1;
				while (control < cubdata->map->row && cubdata->map->map[control][j] && cubdata->map->map[control][j] == ' ')
					control++;
				if (control >= cubdata->map->row)
				{
					j++;
					continue;
				}
				else if (cubdata->map->map[control][j] != '1')
					ft_error("Error:\nThe map is not closed.");
			}
			j++;
		}
		i++;
	}
}

void	right_space(t_cubdata *cubdata, int i)
{
	int	j;
	int	control;

	while (i < cubdata->map->row)
	{
		j = 0;
		while (cubdata->map->map[i][j])
		{
			if (cubdata->map->map[i][j] == ' ')
			{
				control = j + 1;
				while (control < (int)ft_strlen(cubdata->map->map[i]) && cubdata->map->map[i][control] && cubdata->map->map[i][control] == ' ')
					control++;
				if (control >= (int)ft_strlen(cubdata->map->map[i]))
				{
					j++;
					continue;
				}
				else if (cubdata->map->map[i][control] != '1')
					ft_error("Error:\nThe map is not closed.");
			}
			j++;
		}
		i++;
	}
}

void	left_space(t_cubdata *cubdata, int i)
{
	int	j;
	int	control;
	
	while (i < cubdata->map->row)
	{
		j = (int)ft_strlen(cubdata->map->map[i]) - 1;
		while (j > 0 && cubdata->map->map[i][j])
		{
			if (cubdata->map->map[i][j] == ' ')
			{
				control = j - 1;
				while (control > 0 && cubdata->map->map[i][control] && cubdata->map->map[i][control] == ' ')
					control--;
				if (control <= 0)
				{
					j--;
					continue;
				}
				else if (cubdata->map->map[i][control] != '1')
					ft_error("Error:\nThe map is not closed.");
			}
			j--;
		}
		i++;
	}
}

void	is_map_closed(t_cubdata *cubdata)
{
	first_last_line(cubdata);
	under_space(cubdata, 0);
	above_space(cubdata, (cubdata->map->row - 1));
	left_space(cubdata, 0);
	right_space(cubdata, 0);
}
