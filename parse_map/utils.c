/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:14:11 by kgulfida          #+#    #+#             */
/*   Updated: 2025/02/06 12:14:12 by kgulfida         ###   ########.fr       */
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
