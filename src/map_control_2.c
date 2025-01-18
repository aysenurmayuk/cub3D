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
					ft_error("Error:\nThe map is not closed.");
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

void	is_map_closed(t_cubdata *cubdata)
{
	first_last_line(cubdata);
	under_space(cubdata, 0);
	above_space(cubdata, (cubdata->map->row - 1));
	// left_space(cubdata);
	// right_space(cubdata);
}

void	char_check_2(t_cubdata *cubdata)
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
		ft_error("Error:\nThe unacceptable number of players.");
	is_map_closed(cubdata);
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
				ft_error("Error:\nThe map has unwanted charecter.");
			j++;
		}
		i++;
	}
	char_check_2(cubdata);
}

