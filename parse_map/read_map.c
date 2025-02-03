/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:20:17 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/21 19:08:03 by amayuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	cpymap(char *av, t_data *data, int map_start)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = -1;
	fd = open(av, O_RDONLY);
	while (++i < map_start)
	{
		line = get_next_line(fd);
		free(line);
	}
	j = -1;
	while (++j < data->map->row)
		data->map->cpymap[j] = get_next_line(fd);
	data->map->cpymap[j] = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
}

void	map(char *av, t_data *data, int map_start, int i)
{
	int		j;
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	init_map(data);
	while (++i < map_start)
	{
		line = get_next_line(fd);
		free(line);
	}
	j = -1;
	while (++j < data->map->row)
		data->map->map[j] = get_next_line(fd);
	data->map->map[j] = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	cpymap(av, data, map_start);
}

int	texture_skip(char **line, char **trimmed, t_data *data, int *i)
{
	if (*trimmed[0] == 'C' || *trimmed[0] == 'S' || *trimmed[0] == 'N'
		|| *trimmed[0] == 'W' || *trimmed[0] == 'F' || *trimmed[0] == 'E'
		|| (*trimmed[0] == '\n' && data->map->row == 0))
	{
		(*i)++;
		free(*trimmed);
		free(*line);
		return (1);
	}
	return (0);
}

void	multiple_map_check(int fd, t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (*line != '\n')
			ft_error("Error\nMultiple map.\n", data);
		free(line);
	}
	close(fd);
	if (data->map->row == 0)
		ft_error("Error\nThere is no map.\n", data);
}

void	map_check(char *av, t_data *data, char *line, char *trimmed)
{
	int	fd;
	int	i;

	fd = open(av, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		trimmed = ft_strtrim(line, " ");
		if (texture_skip(&line, &trimmed, data, &i))
			continue ;
		if (trimmed[0] == '\n' && data->map->row != 0)
		{
			free(trimmed);
			free(line);
			break ;
		}
		data->map->row++;
		free(trimmed);
		free(line);
	}
	multiple_map_check(fd, data);
	map(av, data, i, -1);
}
