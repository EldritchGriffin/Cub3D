/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:18:18 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/09 20:21:55 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_quit(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

char	assign_ray_orient(double ra, int is_v)
{
	if (is_v)
	{
		if (get_dir_h(ra) == 1)
			return ('E');
		else
			return ('W');
	}
	else
	{
		if (get_dir_v(ra) == 1)
			return ('S');
		else
			return ('N');
	}
}

void	loop_rays(t_data *data)
{
	int		i;
	double	ra;

	data->rays = malloc(sizeof(t_ray) * data->mlx->w_w - 1);
	i = data->mlx->w_w - 1;
	while (i >= 0)
	{
		ra = (data->ply->pa + 30.0) - ((double)(i)*data->abr);
		ra = limit_angles(ra);
		data->rays[i].dist = cast_ray(data, i, ra);
		data->rays[i].orient = assign_ray_orient(ra, data->rays[i].is_v);
		i--;
	}
}

void	render_sky(t_data *data, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->mlx->w_h / 2)
	{
		x = 0;
		while (x < data->mlx->w_w)
		{
			pixel_put_img(img, x, y, data->lvl->cl_c);
			x++;
		}
		y++;
	}
}

void	render_floor(t_data *data, t_img *img)
{
	int	x;
	int	y;

	y = data->mlx->w_h / 2;
	while (y < data->mlx->w_h)
	{
		x = 0;
		while (x < data->mlx->w_w)
		{
			pixel_put_img(img, x, y, data->lvl->fl_c);
			x++;
		}
		y++;
	}
}

void	is_collided(double x, double y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = x / UNIT;
	map_y = y / UNIT;
	if (data->lvl->only_map[map_y][map_x]
		&& data->lvl->only_map[map_y][map_x] == '1')
		return ;
	if (data->lvl->only_map[map_y][(int)data->ply->p_pos->x / UNIT] == '1'
			&& data->lvl->only_map[(int)data->ply->p_pos->y
				/ UNIT][map_x] == '1')
		return ;
	else
	{
		data->ply->p_pos->x = x;
		data->ply->p_pos->y = y;
	}
	return ;
}
