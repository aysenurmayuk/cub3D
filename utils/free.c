/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:52 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/15 18:44:28 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

// void    free_texture(t_textures *texture)
// {
//     if(texture->floor)
//         double_free(texture->floor);
//     if(texture->ceiling)
//         double_free(texture->ceiling);
//     // if(texture->north)
//     //     free(texture->north);
//     // if(texture->south)
//     //     free(texture->south);
//     // if(texture->west)
//     //     free(texture->west);
//     // if(texture->east)
//     //     free(texture->east);
// }


void    ft_free(t_data *data)
{
    if(data->map->map)
        double_free(data->map->map);
    if(data->map->map)
        double_free(data->map->cpymap);
    free(data->map);
    free(data->game);
    free(data->parse);
    free(data->player);
    // free_texture(data->texture);
    // free(data->texture);
}

void double_free(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}
