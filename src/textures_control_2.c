/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_control_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysenurmayuk <aysenurmayuk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:06:52 by aysenurmayu       #+#    #+#             */
/*   Updated: 2025/01/10 23:43:48 by aysenurmayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void rgb_validate(char *str)
{
    char **rgb;
    int num;
    int i;
    int j;
    
    i = 0;
    rgb = ft_split(str, ',');
    if (!rgb)
        ft_error("Error\nMemory allocation failed.");
    while (rgb[i])
    {
        j = 0;
        while (rgb[i][j] != '\0' && rgb[i][j] != '\t' && rgb[i][j] != ' ')
        {
            //printf("%c\n", rgb[i][j]); //C 225     ,99 7,4  hatalı okuma yapıyor düzeltilecek !!!
            if (!ft_isdigit(rgb[i][j]))
            {
                double_free(rgb);
                ft_error("Error\nRGB values must be digits.");
            }
            j++;
        }
        num = ft_atoi(rgb[i]);
        if (num < 0 || num > 255)
        {
            double_free(rgb);
            ft_error("Error\nRGB value must be between 0 and 255.");
        }
        i++;
    }
    if (i != 3) 
    {
        double_free(rgb);
        ft_error("Error\nRGB must have 3 components.");
    }
    double_free(rgb);
}

void check_color_line(char *str, t_cubdata *cubdata)
{
    char *trimmed;

    trimmed = ft_strtrim(str + 2, " \t\n");
    if (str[0] == 'F' && str[1] == ' ')
    {
        cubdata->textture->floor = ft_strdup(trimmed);
        rgb_validate(cubdata->textture->floor);
    }
    else if (str[0] == 'C' && str[1] == ' ')
    {
        cubdata->textture->ceiling = ft_strdup(trimmed);
        rgb_validate(cubdata->textture->ceiling);
    }
    free(trimmed);
}

void check_xpm_extension(char *texture)
{
    int len;
    
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
