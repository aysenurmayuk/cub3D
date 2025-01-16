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

void    ft_free(t_cubdata *cubdata)
{
    if(cubdata->map->map)
        double_free(cubdata->map->map);
    if(cubdata->map->map)
        double_free(cubdata->map->cpymap);
    free(cubdata->map);
    free(cubdata->mlx);
    free(cubdata->parse);
    free(cubdata->player);
    // free_texture(cubdata->textture);
    // free(cubdata->textture);
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
