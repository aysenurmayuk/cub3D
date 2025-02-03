#include "../lib/cub3d.h"

static void	xpm_extension_check(char *texture, t_data *data)
{
	int	fd;
	int	len;

	fd = open(texture, O_RDWR);
	if (fd == -1)
	{
		close(fd);
		ft_xpm_error("Error\nTexture file can not open.\n", data);
	}
	close(fd);
	if (!texture)
		ft_xpm_error("Error\nMissing texture file path.\n", data);
	len = ft_strlen(texture);
	if (texture[len - 1] != 'm' || texture[len - 2] != 'p' || texture[len
			- 3] != 'x' || texture[len - 4] != '.')
		ft_xpm_error("Error\nTexture file must have a .xpm extension.\n", data);
}

static void	xpm_check_2(char *str, t_data *data)
{
	if (str[0] == 'W' && str[1] == 'E')
	{
		str += 2;
		while (str && *str == ' ')
			str++;
		data->texture->west = ft_strdup(str);
		xpm_extension_check(data->texture->west, data);
	}
	else if (str[0] == 'E' && str[1] == 'A')
	{
		str += 2;
		while (str && *str == ' ')
			str++;
		data->texture->east = ft_strdup(str);
		xpm_extension_check(data->texture->east, data);
	}
}

void	xpm_check(char *str, t_data *data)
{
	if (str[0] == 'N' && str[1] == 'O')
	{
		str += 2;
		while (str && *str == ' ')
			str++;
		data->texture->north = ft_strdup(str);
		xpm_extension_check(data->texture->north, data);
	}
	else if (str[0] == 'S' && str[1] == 'O')
	{
		str += 2;
		while (str && *str == ' ')
			str++;
		data->texture->south = ft_strdup(str);
		xpm_extension_check(data->texture->south, data);
	}
	xpm_check_2(str, data);
}
