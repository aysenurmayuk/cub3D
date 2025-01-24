#include "../lib/cub3d.h"

void	look_left(t_data *data, double turn_dir)
{
	data->player->turn_angle +=  turn_dir * data->game->turn_speed;
	data->player->dir_x = cos(data->player->turn_angle);
}

void	look_right(t_data *data, double turn_dir)
{
	data->player->turn_angle +=  turn_dir * data->game->turn_speed;
	data->player->dir_x = sin(data->player->turn_angle);
}