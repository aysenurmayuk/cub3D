/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:52 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/16 16:33:02 by kgulfida         ###   ########.fr       */
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

static void texture_count_check(t_cubdata *cubdata)
{
    if(cubdata->parse->no != 1 || cubdata->parse->so != 1 || cubdata->parse->we != 1 
        || cubdata->parse->ea != 1 || cubdata->parse->c != 1 || cubdata->parse->f != 1)
    {
        ft_free(cubdata);
        ft_error("Error\nTexture failed.");
    }
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
        if(trimmed[0] != 'C' && trimmed[0] != 'S' && trimmed[0] != 'N' && trimmed[0] != 'W'
            && trimmed[0] != 'F' && trimmed[0] != 'E' && trimmed[0] != '1' && trimmed[0] != '\n')
            ft_error("Error\nThere are unwanted characters in the file.");
        texture_count(trimmed, cubdata);
                is_map_at_eof(trimmed, cubdata);
        xpm_check(trimmed, cubdata);
        color_line_check(trimmed, cubdata, 0);
        free(line);
        free(trimmed);
    }
    texture_count_check(cubdata);
}
