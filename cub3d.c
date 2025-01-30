/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:46 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/21 18:58:21 by amayuk           ###   ########.fr       */
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
	if (!data->map || !data->game || !data->parse || !data->key
		|| !data->player || !data->texture || !data->raycast)
		ft_error("Error\nMalloc problem.");
	init_parse(data);
	init_texture(data);
	init_game(data);
	init_key(data);
	data->player->plane_x = 0; //yatay düzleme paralel bir şekilde baktığı için
	data->player->plane_y = 0.66; //insan gözünün görüş açısı 60-70 derece arasında
}

void	av_check(char *av)
{
	int	fd;
	int	len;

	fd = open(av, O_RDWR);
	if (fd == -1)
	{
		close(fd);
		ft_error("Error\nFile can not open.");
	}
	close(fd);
	len = ft_strlen(av);
	if (av[len - 1] != 'b' || av[len - 2] != 'u' || av[len - 3] != 'c' || av[len
		- 4] != '.')
		ft_error("Error\nThe file is not '.cub' extension.");
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error("Error\nNumber of invalid argument.");
	av_check(av[1]);
	// data = malloc(sizeof(t_data));
	// if (!data)
	// 	ft_error("Error\nMalloc problem");
	init_data(&data);
	textures_check(av[1], &data);
	map_check(av[1], &data, NULL, NULL);
	char_check(&data);
	flood_fill_check(&data);
	is_map_closed(&data);
	game(&data);
	return (0);
}


