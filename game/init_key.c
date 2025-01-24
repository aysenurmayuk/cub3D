#include "../lib/cub3d.h"

int	key_press(int key_code, t_data *data)
{
	if (key_code == 53)
	{
		write(1, "Game closed!", 12);
		mlx_destroy_window(data->game->mlx, data->game->window);
		exit(0);
	}
	if (key_code == 13)
		data->key->w = 1;
	else if (key_code == 1)
		data->key->s = 1;
	else if (key_code == 0)
		data->key->a = 1;
	else if (key_code == 2)
		data->key->d = 1;
	if (key_code == 123)
		data->key->left = 1;
	else if (key_code == 124)
		data->key->right = 1;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == 13)
		data->key->w = 0;
	if (key == 1)
		data->key->s = 0;
	if (key == 0)
		data->key->a = 0;
	if (key == 2)
		data->key->d = 0;
	if (key == 123)
		data->key->left = 0;
	if (key == 124)
		data->key->right = 0;
	return (0);
}