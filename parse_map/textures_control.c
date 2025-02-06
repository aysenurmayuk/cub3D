/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:52 by kgulfida          #+#    #+#             */
/*   Updated: 2025/02/06 13:29:07 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

static void	texture_count(char *trimmed, t_data *data)
{
	if (trimmed[0] == 'N' && trimmed[1] == 'O' && trimmed[2] == ' ')
		data->parse->no++;
	else if (trimmed[0] == 'S' && trimmed[1] == 'O' && trimmed[2] == ' ')
		data->parse->so++;
	else if (trimmed[0] == 'W' && trimmed[1] == 'E' && trimmed[2] == ' ')
		data->parse->we++;
	else if (trimmed[0] == 'E' && trimmed[1] == 'A' && trimmed[2] == ' ')
		data->parse->ea++;
	else if (trimmed[0] == 'C' && trimmed[1] == ' ')
		data->parse->c++;
	else if (trimmed[0] == 'F' && trimmed[1] == ' ')
		data->parse->f++;
}

static void	texture_count_check(t_data *data)
{
	if (data->parse->no != 1 || data->parse->so != 1 || data->parse->we != 1
		|| data->parse->ea != 1 || data->parse->c != 1 || data->parse->f != 1)
		ft_malloc_error("Error\nThe wrong number of textures.\n", data);
}

static void	free_gnl(int fd, char **trimmed, char **line)
{
	free(*line);
	free(*trimmed);
	finish_gnl(fd);
	exit(1);
}

void	textures_check_2(char *av, t_data *data, int fd)
{
	char	*line;
	char	*trimmed;

	init_parse(data);
	fd = open(av, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		trimmed = ft_strtrim(line, " \n");
		texture_count(trimmed, data);
		if (trimmed[0] == '1' && (data->parse->no == 0 || data->parse->so == 0
				|| data->parse->we == 0 || data->parse->ea == 0
				|| data->parse->c == 0 || data->parse->f == 0))
		{
			ft_texture_error("Error\nThe map error.\n", data);
			free_gnl(fd, &trimmed, &line);
		}
		if (xpm_check(trimmed, data) || color_line_check(trimmed, data))
			free_gnl(fd, &trimmed, &line);
		free(line);
		free(trimmed);
	}
	close(fd);
}

void	textures_check(char *av, t_data *data)
{
	char	*line;
	char	*trimmed;
	int		fd;

	fd = open(av, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		trimmed = ft_strtrim(line, " ");
		if (trimmed && trimmed[0] != 'C' && trimmed[0] != 'S'
			&& trimmed[0] != 'N' && trimmed[0] != 'W' && trimmed[0] != 'F'
			&& trimmed[0] != 'E' && trimmed[0] != '1' && trimmed[0] != '\n'
			&& trimmed[0] != '\0')
		{
			ft_texture_error("Error\nThe map error.\n", data);
			free_gnl(fd, &trimmed, &line);
		}
		texture_count(trimmed, data);
		free(line);
		free(trimmed);
	}
	close(fd);
	texture_count_check(data);
}
