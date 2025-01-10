/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysenurmayuk <aysenurmayuk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:52 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/10 23:39:12 by aysenurmayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void    av_check(char *av)
{
    int fd;
    int len;
    
    fd = open(av, O_RDWR);
    if(fd <= 0)
    {
        close(fd);
        ft_error("Error\nFile can not open.");
    }
    close(fd);
    len = ft_strlen(av);
    if(av[len - 1] != 'b' || av[len - 2] != 'u' || av[len - 3] != 'c' || av[len - 4] != '.')
        ft_error("Error: The map is not '.cub' extension.");
}

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


static void texture_count(char  *trimmed, t_cubdata *cubdata)
{
    if (trimmed[0] == 'N' && trimmed[1] == 'O'  && trimmed[2] == ' ')
        cubdata->parse->no++;
    else if (trimmed[0] == 'S' && trimmed[1] == 'O'  && trimmed[2] == ' ')
        cubdata->parse->so++;
    else if (trimmed[0] == 'W' && trimmed[1] == 'E'  && trimmed[2] == ' ')
        cubdata->parse->we++;
    else if (trimmed[0] == 'E' && trimmed[1] == 'A'  && trimmed[2] == ' ')
        cubdata->parse->ea++;
    else if (trimmed[0] == 'C' && trimmed[1] == ' ')
        cubdata->parse->c++;
    else if (trimmed[0] == 'F'  && trimmed[1] == ' ')
        cubdata->parse->f++;
}

void    textures_check(char *av, t_cubdata *cubdata)
{
    char    *line;
    char    *trimmed;
    int     fd;

    fd = open(av, O_RDONLY);
    if(fd == -1)
        ft_error("Error\nDirectory failed.");
    while (1)
    {
        line = get_next_line(fd);
        if(line == NULL)
            break;
        trimmed = ft_strtrim(line, " ");
        texture_count(trimmed, cubdata);
        xpm_check(trimmed, cubdata);
        check_color_line(trimmed, cubdata);
        free(line);
        free(trimmed);
    }
    if(cubdata->parse->no != 1 || cubdata->parse->so != 1 || cubdata->parse->we != 1 
        || cubdata->parse->ea != 1 || cubdata->parse->c != 1 || cubdata->parse->f != 1)
    {
        ft_free(cubdata);
        ft_error("Error\nTexture failed.");
    }
}
