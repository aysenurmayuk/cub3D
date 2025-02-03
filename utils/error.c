/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:52 by kgulfida          #+#    #+#             */
/*   Updated: 2025/01/21 18:50:51 by amayuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_error(char *msg, t_data *data)
{
	ft_full_free(data);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	ft_xpm_error(char *msg, t_data *data)
{
	if (data->texture->east)
		free(data->texture->east);
	if (data->texture->west)
		free(data->texture->west);
	if (data->texture->north)
		free(data->texture->north);
	if (data->texture->south)
		free(data->texture->south);
	free(data->texture);
	free(data->game);
	free(data->parse);
	free(data->player);
	free(data->key);
	free(data->raycast);
	free(data->map);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	ft_rgb_error(char *msg, t_data *data)
{
	if (data->texture->east)
		free(data->texture->east);
	if (data->texture->west)
		free(data->texture->west);
	if (data->texture->north)
		free(data->texture->north);
	if (data->texture->south)
		free(data->texture->south);
	if (data->texture->floor)
		double_free(data->texture->floor);
	if (data->texture->ceiling)
		double_free(data->texture->ceiling);
	free(data->texture);
	free(data->game);
	free(data->parse);
	free(data->player);
	free(data->key);
	free(data->raycast);
	free(data->map);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	ft_malloc_error(char *msg, t_data *data)
{
	if (data->map)
		free(data->map);
	if (data->game)
		free(data->game);
	if (data->parse)
		free(data->parse);
	if (data->key)
		free(data->key);
	if (data->player)
		free(data->player);
	if (data->texture)
		free(data->texture);
	if (data->raycast)
		free(data->raycast);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	ft_text_error(char *msg, char **line, char **trimmed, t_data *data)
{
	free(*line);
	free(*trimmed);
	free(data->map);
	free(data->game);
	free(data->parse);
	free(data->key);
	free(data->player);
	free(data->texture);
	free(data->raycast);
	write(2, msg, ft_strlen(msg));
	exit(1);
}
