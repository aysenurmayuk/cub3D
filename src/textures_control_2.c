/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_control_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:06:52 by aysenurmayu       #+#    #+#             */
/*   Updated: 2025/01/13 16:53:29 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void rgb_validate(char **rgb)
{
    char    *rgb_i;
    int     num;
    int     i;
    int     j;
    
    i = 0;
    while (rgb[i])
    {
        j = 0;
        rgb_i = ft_strtrim(rgb[i], " \t\n");
        while (rgb_i[j])
        {
            if (!ft_isdigit(rgb_i[j]))
            {
                free(rgb_i);
                ft_error("Error\nRGB values must be digits.");
            }
            j++;
        }
        num = ft_atoi(rgb[i]);
        free(rgb_i);
        if (num < 0 || num > 255)
            ft_error("Error\nRGB value must be between 0 and 255.");
        i++;
    }
}

void check_color_line(char *str, t_cubdata *cubdata, int i)
{
    if (str[0] == 'F' && str[1] == ' ')
    {
        cubdata->textture->floor = ft_split(str + 2, ',');
        while (cubdata->textture->floor[i])
            i++;
        if (i != 3) 
        {
            double_free(cubdata->textture->floor);
            ft_error("Error\nRGB must have 3 components.");
        }
        rgb_validate(cubdata->textture->floor);
    }
    else if (str[0] == 'C' && str[1] == ' ')
    {
        cubdata->textture->ceiling = ft_split(str + 2, ',');
        while (cubdata->textture->ceiling[i])
            i++;
        if (i != 3) 
        {
            double_free(cubdata->textture->ceiling);
            ft_error("Error\nRGB must have 3 components.");
        }
        rgb_validate(cubdata->textture->ceiling);
    }
}

void check_xpm_extension(char *texture)
{
    int fd;
    int len;
    
    fd = open(texture, O_RDWR);
    if(fd <= 0)
    {
        close(fd);
        ft_error("Error\nTexture file can not open.");
    }
    close(fd); 
    if (!texture)
        ft_error("Error\n Missing texture file path.");
    len = ft_strlen(texture);
    if (texture[len - 1] != 'm' || texture[len - 2] != 'p' || texture[len - 3] != 'x' || texture[len - 4] != '.')
        ft_error("Error\nTexture file must have a .xpm extension.");
}

void    xpm_check(char *str, t_cubdata *cubdata)
{
    char    *trimmed;

    trimmed = ft_strtrim(str + 2, " \t\n");
    if (str[0] == 'N' && str[1] == 'O')
    {
        cubdata->textture->north = ft_strdup(trimmed); 
        check_xpm_extension(cubdata->textture->north);
    }
    else if (str[0] == 'S' && str[1] == 'O')
    {
        cubdata->textture->south = ft_strdup(trimmed);
        check_xpm_extension(cubdata->textture->south);
    }
    else if (str[0] == 'W' && str[1] == 'E')
    {
        cubdata->textture->west = ft_strdup(trimmed);
        check_xpm_extension(cubdata->textture->west);
    }
    else if (str[0] == 'E' && str[1] == 'A')
    {
        cubdata->textture->east = ft_strdup(trimmed);
        check_xpm_extension(cubdata->textture->east);
    }
    free(trimmed);
}
