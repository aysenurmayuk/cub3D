/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:14:11 by kgulfida          #+#    #+#             */
/*   Updated: 2025/02/06 20:11:12 by amayuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	finish_gnl(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
}

int	check_c(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((ft_isalnum(line[i]) || ft_isalpha(line[i])) && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

void	is_map_closed(t_data *data)
{
	first_last_line(data);
	under_space(data, -1, data->map->row);
	above_space(data, (data->map->row - 1));
	left_space(data, -1);
	right_space(data, -1);
	check_all_field(data, -1);
}

int	free_rgb(char **rgb_i, char *msg, t_data *data)
{
	free(*rgb_i);
	ft_texture_error(msg, data);
	return (1);
}

int	text_check(char *str)
{
	if (str && str[0] != 'C' && str[0] != 'S' && str[0] != 'N' && str[0] != 'W'
		&& str[0] != 'F' && str[0] != 'E' && str[0] != '1' && str[0] != '\n'
		&& str[0] != '\0')
		return (1);
	if (str && ((str[0] == 'E' && str[1] != 'A') || (str[0] == 'S'
				&& str[1] != 'O') || (str[0] == 'W' && str[1] != 'E')
			|| (str[0] == 'N' && str[1] != 'O') || (str[0] == 'F'
				&& str[1] != ' ') || (str[0] == 'C' && str[1] != ' ')))
		return (1);
	if (str && ((str[0] == 'E' && str[1] == 'A' && str[2] != ' ')
			|| (str[0] == 'S' && str[1] != 'O' && str[2] != ' ')
			|| (str[0] == 'W' && str[1] != 'E' && str[2] != ' ')
			|| (str[0] == 'N' && str[1] != 'O' && str[2] != ' ')
			|| (str[0] == 'F' && str[1] != ' ') || (str[0] == 'C'
				&& str[1] != ' ')))
		return (1);
	return (0);
}
