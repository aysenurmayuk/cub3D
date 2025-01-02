/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysenurmayuk <aysenurmayuk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:52 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/02 13:23:16 by aysenurmayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void map_check(char *argv, t_cubdata *game)
{
    int fd;
    int len;
    
    fd = open(argv, O_RDWR);
    if(fd <= 0)
    {
        close(fd);
        ft_error("Error: File can not open.", game);
    }
    close(fd);
    len = ft_strlen(argv);
    if(argv[len - 1] == 'b' && argv[len - 2] == 'u' 
        && argv[len - 3] == 'c' && argv[len - 4] == '.')
        return ;
    else
    {
        ft_error("Error: The map is not '.cub' extension.", game);
    }
}
