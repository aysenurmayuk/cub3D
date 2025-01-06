/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysenurmayuk <aysenurmayuk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:52 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/06 13:53:57 by aysenurmayu      ###   ########.fr       */
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
    if(argv[len - 1] != 'b' || argv[len - 2] != 'u' || argv[len - 3] != 'c' || argv[len - 4] != '.')
        ft_error("Error: The map is not '.cub' extension.");
}

void    texture_count(char  *trimmed, t_cubdata *cubdata)
{
    if (trimmed[0] == 'N' && trimmed[1] == 'O')
        cubdata->parse->no++;
    else if (trimmed[0] == 'S' && trimmed[1] == 'O')
        cubdata->parse->so++;
    else if (trimmed[0] == 'W' && trimmed[1] == 'E')
        cubdata->parse->we++;
    else if (trimmed[0] == 'E' && trimmed[1] == 'A')
        cubdata->parse->ea++;
    else if (trimmed[0] == 'C' && trimmed[1] == ' ')
        cubdata->parse->c++;
    else if (trimmed[0] == 'F'  && trimmed[1] == ' ')
        cubdata->parse->f++;
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

void xpm_check(char *trimmed, t_cubdata *cubdata)
{
    if (trimmed[0] == 'N' && trimmed[1] == 'O')
    {
        cubdata->textture->north = ft_strdup(trimmed + 3); 
        check_xpm_extension(cubdata->textture->north);
    }
    else if (trimmed[0] == 'S' && trimmed[1] == 'O')
    {
        cubdata->textture->south = ft_strdup(trimmed + 3);
        check_xpm_extension(cubdata->textture->south);
    }
    else if (trimmed[0] == 'W' && trimmed[1] == 'E')
    {
        cubdata->textture->west = ft_strdup(trimmed + 3);
        check_xpm_extension(cubdata->textture->west);
    }
    else if (trimmed[0] == 'E' && trimmed[1] == 'A')
    {
        cubdata->textture->east = ft_strdup(trimmed + 3);
        check_xpm_extension(cubdata->textture->east);
    }
    // C, F check
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
        if (line == NULL)
            break;
        trimmed = ft_strtrim(line, " ");
        printf("%s", trimmed);
        texture_count(trimmed, cubdata);
        xpm_check(trimmed, cubdata);
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
