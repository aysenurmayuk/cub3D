/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_control_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:06:52 by amayuk            #+#    #+#             */
/*   Updated: 2025/01/20 18:25:33 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

// void	number_check(char *rgb)
// {

// }

void	rgb_validate(char **rgb, int i, int j)
{
	char	*rgb_i;
	char	*control;
	int		num;
	int k;

	while (rgb[i])
	{
		j = 0;
		k = 0;
		rgb_i = ft_strtrim(rgb[i], " \n");
		if (rgb_i[0] == '+')
			j++;
		while (rgb_i[k] == '0')
			k++;
		while (rgb_i[j])
		{
			if (!ft_isdigit(rgb_i[j]))
			{
				free(rgb_i);
				ft_error("Error\nRGB values must be digits.");
			}
			j++;
		}
		num = ft_atoi(rgb_i);
		control = ft_itoa(num);
		if (num < 0 || num > 255 || ft_strncmp(rgb_i + k, control,
			ft_strlen(control)))
		{
			free(rgb_i);
			free(control);
			ft_error("Error\nRGB value must be between 0 and 255.");
		}
		else
		{
			free(rgb_i);
			free(control);
		}
		i++;
	}
}

void	color_line_component_count(char **str, t_cubdata *cubdata)
{
	int	i;
	int	j;
	int	flag;

	(void)cubdata; // ft_error fonksiyonuna gönderilecek
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

void	color_line_check(char *str, t_cubdata *cubdata, int i)
{
	(void)i;
	if (str[0] == 'F' && str[1] == ' ')
	{
		if (cubdata->textture->floor == NULL)
			cubdata->textture->floor = ft_split(str + 2, ',');
		color_line_component_count(cubdata->textture->floor, cubdata);
		rgb_validate(cubdata->textture->floor, 0, 0);
	}
	else if (str[0] == 'C' && str[1] == ' ')
	{
		if (cubdata->textture->ceiling == NULL)
			cubdata->textture->ceiling = ft_split(str + 2, ',');
		color_line_component_count(cubdata->textture->ceiling, cubdata);
		rgb_validate(cubdata->textture->ceiling, 0, 0);
	}
}

void	xpm_extension_check(char *texture)
{
	int	fd;
	int	len;

	fd = open(texture, O_RDWR);
	if (fd <= 0)
	{
		close(fd);
		ft_error("Error\nTexture file can not open.");
	}
	close(fd);
	if (!texture)
		ft_error("Error\n Missing texture file path.");
	len = ft_strlen(texture);
	if (texture[len - 1] != 'm' || texture[len - 2] != 'p' || texture[len
		- 3] != 'x' || texture[len - 4] != '.')
		ft_error("Error\nTexture file must have a .xpm extension.");
}
