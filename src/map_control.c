/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysenurmayuk <aysenurmayuk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:52 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/02 13:37:54 by aysenurmayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void    argv_check(char *argv)
{
    int fd;
    int len;
    
    fd = open(argv, O_RDWR);
    if(fd <= 0)
    {
        close(fd);
        ft_error("Error: File can not open.");
    }
    close(fd);
    len = ft_strlen(argv);
    if(argv[len - 1] == 'b' && argv[len - 2] == 'u' 
        && argv[len - 3] == 'c' && argv[len - 4] == '.')
        return ;
    else
        ft_error("Error: The map is not '.cub' extension.");
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

void    textures_check(char *argv, t_cubdata *cubdata)
{
    char    *line;
    char    *trimmed;
    int     fd;

    fd = open(argv, O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        trimmed = ft_strtrim(line, " ");
        printf("%s", trimmed);
        if(line == NULL)
            break;
        texture_count(trimmed, 0, cubdata);
        free(line);
        free(trimmed);
    }
    if(cubdata->parse->no != 1 || cubdata->parse->so != 1 || cubdata->parse->we != 1 
        || cubdata->parse->ea != 1 || cubdata->parse->c != 1 || cubdata->parse->f != 1)
    {
        // ft_free(cubdata);
        printf("no:%d so:%d we:%d ea:%d c:%d f:%d\n", cubdata->parse->no , cubdata->parse->so ,cubdata->parse->we 
        , cubdata->parse->ea , cubdata->parse->c ,cubdata->parse->f);
        ft_error("Error\nTexture failed");
        // ft_error("")
    }
}
