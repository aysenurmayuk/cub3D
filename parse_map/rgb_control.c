/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_control_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:06:52 by amayuk            #+#    #+#             */
/*   Updated: 2025/01/21 18:38:30 by amayuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	number_check(char **rgb_i, char **control, int num)
{
	if (num < 0 || num > 255 || ft_strncmp(*rgb_i, *control,
			ft_strlen(*control)))
	{
		free(*rgb_i);
		free(*control);
		ft_error("Error\nRGB value must be between 0 and 255.");
	}
	else
	{
		free(*rgb_i);
		free(*control);
	}
}

void	rgb_validate(char **rgb, int i, int j)
{
	char	*rgb_i;
	char	*control;
	int		num;

	while (rgb[i])
	{
		j = 0;
		rgb_i = ft_strtrim(rgb[i], " \n");
		while (rgb_i[j])
		{
			if (!ft_isdigit(rgb_i[j]))
			{
				free(rgb_i);
				ft_error("Error\nRGB values must be digits.");
			}
			j++;
		}
		num = ft_atoi(rgb[i]);
		control = ft_itoa(num);
		number_check(&rgb_i, &control, num);
		i++;
	}
}

void	color_line_component_count(char **str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (str[i])
	{
		j = 0;
		flag = 0;
		while (str[i][j])
		{
			if (str[i][j] != ' ')
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			ft_error("Error\nRGB must have 3 components.");
		i++;
	}
	if (i != 3)
		ft_error("Error\nRGB must have 3 components.");
}

void	color_line_check(char *str, t_data *data, int i)
{
	(void)i;
	if (str[0] == 'F' && str[1] == ' ')
	{
		if (data->texture->floor == NULL)
			data->texture->floor = ft_split(str + 2, ',');
		color_line_component_count(data->texture->floor);
		rgb_validate(data->texture->floor, 0, 0);
	}
	else if (str[0] == 'C' && str[1] == ' ')
	{
		if (data->texture->ceiling == NULL)
			data->texture->ceiling = ft_split(str + 2, ',');
		color_line_component_count(data->texture->ceiling);
		rgb_validate(data->texture->ceiling, 0, 0);
	}
}
