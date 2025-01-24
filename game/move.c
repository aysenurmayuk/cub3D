#include "../lib/cub3d.h"

void	move_up(t_data *data, double turn_dir)
{
	double	x;
	double	y;

	data->player->turn_angle +=  turn_dir * data->game->turn_speed;
	x = data->player->pos_x + cos(data->player->turn_angle) * data->game->walk_speed;
	y = data->player->pos_y + sin(data->player->turn_angle) * data->game->walk_speed;
	if (data->map->map[(int)data->player->pos_y][(int)x] != '1')
		data->player->pos_x = x;
	if (data->map->map[(int)y][(int)data->player->pos_x] != '1')
		data->player->pos_y = y;
}

void	move_down(t_data *data, double turn_dir)
{
	double	x;
	double	y;
	
	data->player->turn_angle +=  turn_dir * data->game->turn_speed;
	x = data->player->pos_x - cos(data->player->turn_angle) * data->game->walk_speed;
	y = data->player->pos_y - sin(data->player->turn_angle) * data->game->walk_speed;
	if (data->map->map[(int)data->player->pos_y][(int)x] != '1')
		data->player->pos_x = x;
	if (data->map->map[(int)y][(int)data->player->pos_x] != '1')
		data->player->pos_y = y;
}

void	move_left(t_data *data, double turn_dir)
{
	double	x;
	double	y;
	
	data->player->turn_angle +=  turn_dir * data->game->turn_speed;
	x = data->player->pos_x - cos(data->player->turn_angle + 90) * data->game->walk_speed;
	y = data->player->pos_y - sin(data->player->turn_angle + 90) * data->game->walk_speed;
	if (data->map->map[(int)data->player->pos_y][(int)x] != '1')
		data->player->pos_x = x;
	if (data->map->map[(int)y][(int)data->player->pos_x] != '1')
		data->player->pos_y = y;
}

void	move_right(t_data *data, double turn_dir)
{
	double	x;
	double	y;
	
	data->player->turn_angle +=  turn_dir * data->game->turn_speed;
	x = data->player->pos_x + cos(data->player->turn_angle + 90) * data->game->walk_speed;
	y = data->player->pos_y + sin(data->player->turn_angle + 90) * data->game->walk_speed;
	if (data->map->map[(int)data->player->pos_y][(int)x] != '1')
		data->player->pos_x = x;
	if (data->map->map[(int)y][(int)data->player->pos_x] != '1')
		data->player->pos_y = y;
}
