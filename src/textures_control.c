/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:52 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/17 20:30:19 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	xpm_check(char *str, t_cubdata *cubdata)
{
	char	*trimmed;

	trimmed = ft_strtrim(str + 2, " \t\n");
	if (str[0] == 'N' && str[1] == 'O')
	{
		cubdata->textture->north = trimmed;
		xpm_extension_check(cubdata->textture->north);
	}
	else if (str[0] == 'S' && str[1] == 'O')
	{
		cubdata->textture->south = trimmed;
		xpm_extension_check(cubdata->textture->south);
	}
	else if (str[0] == 'W' && str[1] == 'E')
	{
		cubdata->textture->west = trimmed;
		xpm_extension_check(cubdata->textture->west);
	}
	else if (str[0] == 'E' && str[1] == 'A')
	{
		cubdata->textture->east = trimmed;
		xpm_extension_check(cubdata->textture->east);
	}
	free(trimmed);
}

static void	texture_count(char *trimmed, t_cubdata *cubdata)
{
	if (trimmed[0] == 'N' && trimmed[1] == 'O' && trimmed[2] == ' ')
		cubdata->parse->no++;
	else if (trimmed[0] == 'S' && trimmed[1] == 'O' && trimmed[2] == ' ')
		cubdata->parse->so++;
	else if (trimmed[0] == 'W' && trimmed[1] == 'E' && trimmed[2] == ' ')
		cubdata->parse->we++;
	else if (trimmed[0] == 'E' && trimmed[1] == 'A' && trimmed[2] == ' ')
		cubdata->parse->ea++;
	else if (trimmed[0] == 'C' && trimmed[1] == ' ')
		cubdata->parse->c++;
	else if (trimmed[0] == 'F' && trimmed[1] == ' ')
		cubdata->parse->f++;
}

static void	texture_count_check(t_cubdata *cubdata)
{
	if (cubdata->parse->no != 1 || cubdata->parse->so != 1
		|| cubdata->parse->we != 1 || cubdata->parse->ea != 1
		|| cubdata->parse->c != 1 || cubdata->parse->f != 1)
	{
		// ft_free(cubdata);
		ft_error("Error\nThe wrong number of textures.");
	}
}

void	textures_check_2(char *av, t_cubdata *cubdata)
{
	char	*line;
	char	*trimmed;
	int		fd;

	init_parse(cubdata);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nDirectory failed.");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		trimmed = ft_strtrim(line, " ");
		texture_count(trimmed, cubdata);
		if (trimmed[0] == '1' && (cubdata->parse->no == 0 || cubdata->parse->so == 0
			|| cubdata->parse->we == 0 || cubdata->parse->ea == 0
			|| cubdata->parse->c == 0 || cubdata->parse->f == 0))
			ft_error("Error\nThe map is the wrong place.");
		xpm_check(trimmed, cubdata);
		color_line_check(trimmed, cubdata, 0);
		free(line);
		free(trimmed);
	}
	close(fd);
}

void	textures_check(char *av, t_cubdata *cubdata)
{
	char	*line;
	char	*trimmed;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nDirectory failed.");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		trimmed = ft_strtrim(line, " ");
		if (trimmed[0] != 'C' && trimmed[0] != 'S' && trimmed[0] != 'N'
			&& trimmed[0] != 'W' && trimmed[0] != 'F' && trimmed[0] != 'E'
			&& trimmed[0] != '1' && trimmed[0] != '\n')
			ft_error("Error\nThere are unwanted characters in the file.");
		texture_count(trimmed, cubdata);
		free(line);
		free(trimmed);
	}
	close(fd);
	texture_count_check(cubdata);
	textures_check_2(av, cubdata);
}
