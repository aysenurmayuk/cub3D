/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:46 by kgulfida          #+#    #+#             */
/*   Updated: 2025/02/06 16:23:18 by amayuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3d.h"

void	init_data(t_data *data)
{
	data->parse = malloc(sizeof(t_parse));
	data->texture = malloc(sizeof(t_textures));
	data->map = malloc(sizeof(t_map));
	data->game = malloc(sizeof(t_game));
	data->key = malloc(sizeof(t_keys));
	data->player = malloc(sizeof(t_player));
	data->raycast = malloc(sizeof(t_raycast));
	if (!data->map || !data->game || !data->parse || !data->key || !data->player
		|| !data->texture || !data->raycast)
		ft_malloc_error("Error\nMalloc problem.\n", data);
	init_parse(data);
	init_texture(data);
	init_game(data);
	init_key(data);
}

void	av_check(char *av)
{
	int	fd;
	int	len;

	fd = open(av, O_RDWR);
	if (fd == -1)
	{
		close(fd);
		write(2, "Error\nFile can not open.\n", 26);
		exit (1);
	}
	close(fd);
	len = ft_strlen(av);
	if (av[len - 1] != 'b' || av[len - 2] != 'u' || av[len - 3] != 'c' || av[len
			- 4] != '.')
	{
		write(2, "Error\nThe file is not '.cub' extension.\n", 41);
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		write(2, "Error\nNumber of invalid argument.\n", 35);
		return (1);
	}
	av_check(av[1]);
	init_data(&data);
	textures_check(av[1], &data);
	textures_check_2(av[1], &data, 0);
	map_check(av[1], &data, NULL, NULL);
	char_check(&data);
	flood_fill_check(&data);
	is_map_closed(&data);
	game(&data);
	return (0);
}
