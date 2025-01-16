/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:20:17 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/16 18:19:49 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	is_map_at_eof(char *str, t_cubdata *cubdata)
{
    if(str[0] == '1' && (cubdata->parse->no == 0 || cubdata->parse->so == 0 || cubdata->parse->we == 0
		|| cubdata->parse->ea == 0 || cubdata->parse->c == 0 || cubdata->parse->f == 0))
    {
		ft_free(cubdata);
		ft_error("Error\nThe map is the wrong place.");
	}
}

void	map_check(char *av, t_cubdata *cubdata, char *line, char *trimmed)
{
	int		fd;

	fd = open(av, O_RDONLY);
	cubdata->map->row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		trimmed = ft_strtrim(line, " \t");
		if(trimmed[0] == 'C' || trimmed[0] == 'S' || trimmed[0] == 'N' || trimmed[0] == 'W'
            || trimmed[0] == 'F' || trimmed[0] == 'E' || trimmed[0] == '\n')
		{
			free(trimmed);
			free(line);	
            continue;
		}
		cubdata->map->row++;
		//printf("row:%d\n",cubdata->map->row);
		free(trimmed);
		free(line);
	}
	close(fd);
	free(line);
	if (cubdata->map->row == 0)
		ft_error("Error\nThe map is empty.");
	cubdata->map->map = (char **)malloc(cubdata->map->row * sizeof(char *));
	cubdata->map->cpymap = (char **)malloc(cubdata->map->row * sizeof(char *));
	if (cubdata->map->map == NULL || cubdata->map->cpymap == NULL)
		ft_error("Error:\nMemory problem!");
}

static int	strlen_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	map(char *argv, t_map *game)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(argv, O_RDONLY);
	while (++i < game->row)
		game->map[i] = get_next_line(fd);
	game->col = strlen_newline(game->map[0]);
	close(fd);
	fd = open(argv, O_RDONLY);
	i = -1;
	while (++i < game->row)
		game->cpymap[i] = get_next_line(fd);
	close(fd);
}
