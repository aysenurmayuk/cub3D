/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:52 by kgulfida          #+#    #+#             */
/*   Updated: 2025/02/06 20:12:57 by amayuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_full_free(t_data *data)
{
	if (data->map->map)
		double_free(data->map->map);
	if (data->map->cpymap)
		double_free(data->map->cpymap);
	free(data->map);
	if (data->texture->floor)
		double_free(data->texture->floor);
	if (data->texture->ceiling)
		double_free(data->texture->ceiling);
	free(data->texture->north);
	free(data->texture->south);
	free(data->texture->west);
	free(data->texture->east);
	free(data->texture);
	free(data->parse);
	free(data->player);
	free(data->key);
	free(data->raycast);
}

void	double_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
