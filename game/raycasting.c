#include "../lib/cub3d.h"

void	set_variable(t_data *data, int i)
{
	data->raycast->camera_x = 2 * i / (double)screen_w - 1;
	data->raycast->ray_dir_x = data->player->dir_x + data->player->plane_x
		* data->raycast->camera_x;
	data->raycast->ray_dir_y = data->player->dir_y + data->player->plane_y
		* data->raycast->camera_x;
	data->raycast->map_x = (int)data->player->pos_x;
	data->raycast->map_y = (int)data->player->pos_y;
	data->raycast->delta_x = fabs(1 / data->raycast->ray_dir_x);
	data->raycast->delta_y = fabs(1 / data->raycast->ray_dir_y);
}

void	calculate_step(t_data *data)
{
	if (data->raycast->ray_dir_x < 0)
	{
		data->raycast->step_x = -1;
		data->raycast->side_x = (data->player->pos_x - data->raycast->map_x)
			* data->raycast->delta_x;
	}
	else
	{
		data->raycast->step_x = 1;
		data->raycast->side_x = (data->raycast->map_x + 1.0
				- data->player->pos_x) * data->raycast->delta_x;
	}
	if (data->raycast->ray_dir_y < 0)
	{
		data->raycast->step_y = -1;
		data->raycast->side_y = (data->player->pos_y - data->raycast->map_y)
			* data->raycast->delta_y;
	}
	else
	{
		data->raycast->step_y = 1;
		data->raycast->side_y = (data->raycast->map_y + 1.0
				- data->player->pos_y) * data->raycast->delta_y;
	}
}

int	dda_algorithm(t_data *data)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (data->raycast->side_x < data->raycast->side_y)
		{
			data->raycast->side_x += data->raycast->delta_x;
			data->raycast->map_x += data->raycast->step_x;
			side = 0;
		}
		else
		{
			data->raycast->side_y += data->raycast->delta_y;
			data->raycast->map_y += data->raycast->step_y;
			side = 1;
		}
		if (data->map->map[data->raycast->map_y][data->raycast->map_x] == '1')
			hit = 1;
	}
	return (side);
}

void	set_pixel(t_data *data, int line_h, int side)
{
	if (side == 0)
		data->raycast->hit_x = data->player->pos_y + data->raycast->wall_dist
			* data->raycast->ray_dir_y;
	else
		data->raycast->hit_x = data->player->pos_x + data->raycast->wall_dist
			* data->raycast->ray_dir_x;
	data->raycast->hit_x -= floor(data->raycast->hit_x);
	data->raycast->tex_x = (int)(data->raycast->hit_x * 64);
	data->raycast->per_pix = 1.0 * 64 / line_h;
	data->raycast->tex_y_next = (data->raycast->wall_start - screen_h / 2
			+ line_h / 2) * data->raycast->per_pix;
}

void	put_col(t_data *data, int col, int side)
{
	int	i;
	int	tex_i;
	int	color;

	i = data->raycast->wall_start;
	while (i < data->raycast->wall_end)
	{
		data->raycast->tex_y = (int)data->raycast->tex_y_next
			& (data->game->size - 1);
		data->raycast->tex_y_next += data->raycast->per_pix;
		tex_i = data->raycast->tex_x + data->game->size * data->raycast->tex_y;
		if (data->raycast->ray_dir_x > 0 && side != 1)
			color = data->game->addr_w[tex_i];
		else if (data->raycast->ray_dir_x < 0 && side != 1)
			color = data->game->addr_e[tex_i];
		else if (data->raycast->ray_dir_x <= 2 && data->raycast->ray_dir_y >= 0
			&& side == 1)
			color = data->game->addr_n[tex_i];
		else
			color = data->game->addr_s[tex_i];
		data->game->addr[i * screen_w + col] = color;
		i++;
	}
}
