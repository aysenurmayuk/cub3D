/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:46 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/16 17:12:24 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	init_cubdata(t_cubdata *cubdata)
{
	cubdata->map = malloc(sizeof(t_map));
	cubdata->mlx = malloc(sizeof(t_mlx));
	cubdata->parse = malloc(sizeof(t_parse));
	cubdata->player = malloc(sizeof(t_player));
	cubdata->textture = malloc(sizeof(t_textures));
	init_parse(cubdata);
	init_texture(cubdata);
}

void	av_check(char *av)
{
	int	fd;
	int	len;

	fd = open(av, O_RDWR);
	if (fd <= 0)
	{
		close(fd);
		ft_error("Error\nFile can not open.");
	}
	close(fd);
	len = ft_strlen(av);
	if (av[len - 1] != 'b' || av[len - 2] != 'u' || av[len - 3] != 'c' || av[len
		- 4] != '.')
		ft_error("Error: The map is not '.cub' extension.");
}

int	main(int ac, char **av)
{
	t_cubdata	*cubdata;

	if (ac != 2)
		ft_error("Error: number of invalid argument");
	av_check(av[1]);
	cubdata = malloc(sizeof(t_cubdata));
	if (!cubdata)
		ft_error("Error: malloc problem");
	init_cubdata(cubdata);
	textures_check(av[1], cubdata);
	map_check(av[1], cubdata, NULL, NULL);
	char_check(cubdata);

	// mlx = mlx_init();
	// if (!mlx)
	//     return (1);
	// win = mlx_new_window(mlx, 800, 600, "Cub3D");
	// if (!win)
	//     return (1);
	// mlx_loop(mlx);
	return (0);
}
