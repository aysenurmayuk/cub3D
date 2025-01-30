#include "../lib/cub3d.h"

int	key_press(int key_code, t_data *data)
{
	if (key_code == 65307)
	{
		printf("Game closed!\n");
		mlx_destroy_window(data->game->mlx, data->game->window);
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
