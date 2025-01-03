/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:52 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/03 17:34:08 by kgulfida         ###   ########.fr       */
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
        ft_error("Error: File can not open.");
    }
    close(fd);
    len = ft_strlen(av);
    if(av[len - 1] == 'b' && av[len - 2] == 'u' 
        && av[len - 3] == 'c' && av[len - 4] == '.')
        return ;
    else
        ft_error("Error: The map is not '.cub' extension.");
}

void    xpm_check(char *av, t_cubdata *cubdata)
{
    
}

void    texture_count(char  *trimmed, int i, t_cubdata *cubdata)
{
    if (trimmed[i] == 'N')
        cubdata->parse->no++;
    else if (trimmed[i] == 'S')
        cubdata->parse->so++;
    else if (trimmed[i] == 'W')
        cubdata->parse->we++;
    else if (trimmed[i] == 'E')
        cubdata->parse->ea++;
    else if (trimmed[i] == 'C')
        cubdata->parse->c++;
    else if (trimmed[i] == 'F')
        cubdata->parse->f++;
}

void    textures_check(char *av, t_cubdata *cubdata)
{
    char    *line;
    char    *trimmed;
    int     fd;

    fd = open(av, O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if(line == NULL)
            break;
        trimmed = ft_strtrim(line, " ");
        texture_count(trimmed, 0, cubdata);
        free(line);
        free(trimmed);
    }
    if(cubdata->parse->no != 1 || cubdata->parse->so != 1 || cubdata->parse->we != 1 
        || cubdata->parse->ea != 1 || cubdata->parse->c != 1 || cubdata->parse->f != 1)
    {
        ft_free(cubdata);
        ft_error("Error\nTexture failed");
    }
    xpm_check(av, cubdata);
}
