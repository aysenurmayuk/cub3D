#include "../lib/cub3d.h"

void	destroy_mlx(t_data *data)
{
	if (data->game->img)
		mlx_destroy_image(data->game->mlx, data->game->img);
	if (data->game->no)
		mlx_destroy_image(data->game->mlx, data->game->no);
	if (data->game->so)
		mlx_destroy_image(data->game->mlx, data->game->so);
	if (data->game->ea)
		mlx_destroy_image(data->game->mlx, data->game->ea);
	if (data->game->we)
		mlx_destroy_image(data->game->mlx, data->game->we);
	if (data->game->window)
		mlx_destroy_window(data->game->mlx, data->game->window);
	if (data->game->mlx)
		mlx_destroy_display(data->game->mlx);
	ft_full_free(data);
	if (data->game->mlx)
	{
		free(data->game->mlx);
		data->game->mlx = NULL;
	}
	if (data->game)
	{
		free(data->game);
		data->game = NULL;
	}
}

int	key_press(int key_code, t_data *data)
{
	if (key_code == 65307)
	{
		printf("Game closed!\n");
		destroy_mlx(data);
		exit(0);
	}
	if (key_code == 119)
		data->key->w = 1;
	else if (key_code == 115)
		data->key->s = 1;
	else if (key_code == 97)
		data->key->a = 1;
	else if (key_code == 100)
		data->key->d = 1;
	if (key_code == 65361)
		data->key->left = 1;
	else if (key_code == 65363)
		data->key->right = 1;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == 119)
		data->key->w = 0;
	if (key == 115)
		data->key->s = 0;
	if (key == 97)
		data->key->a = 0;
	if (key == 100)
		data->key->d = 0;
	if (key == 65361)
		data->key->left = 0;
	if (key == 65363)
		data->key->right = 0;
	return (0);
}
