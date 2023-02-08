/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:20:52 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/09 00:05:53 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	diag_move(t_data *data)
{
	float	new_x;
	float	new_y;
	float	rad;

	if (data->ply->d_dir == 1)
		rad = deg_to_rad(limit_angles(data->ply->pa - 90));
	if (data->ply->d_dir == -1)
		rad = deg_to_rad(limit_angles(data->ply->pa + 90));
	new_x = data->ply->p_pos->x + cosf(rad) * MVS * data->ply->mh_dir;
	new_y = data->ply->p_pos->y - sinf(rad) * MVS * data->ply->mh_dir;
	is_collided(new_x, new_y, data);
}

void	p_move(t_data *data)
{
	float	rad;
	float	new_y;
	float	new_x;

	if (data->ply->d_dir != 0)
	{
		diag_move(data);
		return ;
	}
	rad = deg_to_rad(data->ply->pa);
	new_x = data->ply->p_pos->x + cosf(rad) * MVS * data->ply->mv_dir;
	new_y = data->ply->p_pos->y - sinf(rad) * MVS * data->ply->mv_dir;
	is_collided(new_x, new_y, data);
}

void	p_rotate(t_data *data)
{
	data->ply->pa += TRS * data->ply->r_dir;
	data->ply->pa = limit_angles(data->ply->pa);
}

int get_texel(t_data *data, int x, int y, int slice, int is_v)
{
	int		text_x;
	int		text_y;
	unsigned int color;

	text_x = (int)data->rays[x].wall_pos.x % UNIT;
	if (is_v)
	{
		text_x = (int)data->rays[x].wall_pos.y % UNIT;
		text_y = ((y -  ((data->mlx->w_h / 2) - (slice / 2))) * ((double)(double)UNIT / (double)slice));
	}
	else
	{
		text_y = ((y -  ((data->mlx->w_h / 2) - (slice / 2))) * ((double)(double)UNIT / (double)slice));
	}

	mlx_get_color_at(data->img, text_x, text_y, &color);
	return (color);
}





