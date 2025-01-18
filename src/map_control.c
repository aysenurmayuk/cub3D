/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:20:17 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/17 20:29:59 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	cpymap(char *av, t_cubdata *cubdata, int map_start)
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
	while (++j < cubdata->map->row)
		cubdata->map->cpymap[j] = get_next_line(fd);
	close(fd);
}

void	map(char *av, t_cubdata *cubdata, int map_start)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = -1;
	fd = open(av, O_RDONLY);
	init_map(cubdata);
	while (++i < map_start)
	{
		line = get_next_line(fd);
		free(line);
	}
	j = -1;
	while (++j < cubdata->map->row)
		cubdata->map->map[j] = get_next_line(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	cpymap(av, cubdata, map_start);
}

int	map_check_helper(char **line, char **trimmed, t_cubdata *cubdata, int *i)
{
	if (*trimmed[0] == 'C' || *trimmed[0] == 'S' || *trimmed[0] == 'N'
		|| *trimmed[0] == 'W' || *trimmed[0] == 'F' || *trimmed[0] == 'E'
		|| (*trimmed[0] == '\n' && cubdata->map->row == 0))
	{
		(*i)++;
		free(*trimmed);
		free(*line);
		return (1);
	}
	return (0);
}

void	map_check_helper_2(int fd, t_cubdata *cubdata)
{
	char	*line;

	(void)cubdata; // cubdata freelenecek
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (*line != '\n')
			ft_error("Error\nMultiple map.");
		free(line);
	}
	close(fd);
	if (cubdata->map->row == 0)
		ft_error("Error\nThe map is empty.");
}

void	map_check(char *av, t_cubdata *cubdata, char *line, char *trimmed)
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
		trimmed = ft_strtrim(line, " \t");
		if (map_check_helper(&line, &trimmed, cubdata, &i))
			continue ;
		if (trimmed[0] == '\n' && cubdata->map->row != 0)
		{
			free(trimmed);
			free(line);
			break ;
		}
		cubdata->map->row++;
		free(trimmed);
		free(line);
	}
	map_check_helper_2(fd, cubdata);
	map(av, cubdata, i);
}
