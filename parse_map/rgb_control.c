/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:06:52 by amayuk            #+#    #+#             */
/*   Updated: 2025/02/06 13:09:47 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

int	number_check(char **rgb_i, char **control, int num, t_data *data)
{
	if (num < 0 || num > 255 || ft_strncmp(*rgb_i, *control,
			ft_strlen(*control)))
	{
		free(*rgb_i);
		free(*control);
		ft_texture_error("Error\nRGB value must be between 0 and 255.\n", data);
		return (1);
	}
	else
	{
		free(*rgb_i);
		free(*control);
	}
	return (0);
}

int	rgb_validate(char **rgb, int i, int j, t_data *data)
{
	char	*rgb_i;
	char	*control;
	int		num;
	int		flag;

	while (rgb[i])
	{
		j = 0;
		rgb_i = ft_strtrim(rgb[i], " \n");
		while (rgb_i[j])
		{
			if (!ft_isdigit(rgb_i[j]))
			{
				free(rgb_i);
				ft_texture_error("Error\nRGB values must be digits.\n", data);
				return (1);
			}
			j++;
		}
		num = ft_atoi(rgb[i]);
		control = ft_itoa(num);
		flag = number_check(&rgb_i, &control, num, data);
		if (flag)
			return (1);
		i++;
	}
	return (0);
}

int	color_line_component_count(char **str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 3)
	{
		ft_texture_error("Error\nRGB must have 3 components.\n", data);
		return 1;	
	}
	return 0;
}

int	color_comma_count(char *str, t_data *data)
{
	int	i;
	int	c_count;

	i = 0;
	c_count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			c_count++;
		i++;
	}
	if (c_count != 2)
	{
		ft_texture_error("Error\nRGB must have 3 components.\n", data);
		return (1);
	}
	return (0);
}

int	color_line_check(char *str, t_data *data)
{
	if (str[0] == 'F' && str[1] == ' ')
	{
		if (data->texture->floor == NULL)
			data->texture->floor = ft_split(str + 2, ',');
		if (color_comma_count(str, data)
			|| color_line_component_count(data->texture->floor, data)
			|| rgb_validate(data->texture->floor, 0, 0, data))
			return (1);
	}
	else if (str[0] == 'C' && str[1] == ' ')
	{
		if (data->texture->ceiling == NULL)
			data->texture->ceiling = ft_split(str + 2, ',');
		if (color_comma_count(str, data)
			|| color_line_component_count(data->texture->ceiling, data)
			|| rgb_validate(data->texture->ceiling, 0, 0, data))
			return (1);
	}
	return (0);
}
