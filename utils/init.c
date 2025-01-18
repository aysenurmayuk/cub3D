/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:50:33 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/17 20:30:31 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void    init_parse(t_cubdata *cubdata)
{
    cubdata->parse->c = 0;
    cubdata->parse->f = 0;
    cubdata->parse->no = 0;
    cubdata->parse->so = 0;
    cubdata->parse->ea = 0;
    cubdata->parse->we = 0;
}

void    init_texture(t_cubdata *cubdata)
{
    cubdata->textture->ceiling = NULL;
    cubdata->textture->floor = NULL;
    cubdata->textture->north = NULL;
    cubdata->textture->south = NULL;
    cubdata->textture->west = NULL;
    cubdata->textture->east = NULL;
    cubdata->map->cpymap = NULL;
    cubdata->map->map = NULL;
    cubdata->map->row = 0;
    cubdata->map->player_count = 0;
}

void    init_map(t_cubdata *cubdata)
{
    cubdata->map->map = (char **)malloc(cubdata->map->row * sizeof(char *));
	cubdata->map->cpymap = (char **)malloc(cubdata->map->row * sizeof(char *));
	if (cubdata->map->map == NULL || cubdata->map->cpymap == NULL)
		ft_error("Error:\nMemory problem!");
}
