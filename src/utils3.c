/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:21:55 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/09 20:28:43 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	render_slice(t_data *data, int slice, int x)
{
	int				y;
	unsigned int	color;

	color = 0;
	y = (data->mlx->w_h / 2) - (slice / 2);
	if (y < 0)
		y = 0;
	while (y <= (data->mlx->w_h / 2) + (slice / 2))
	{
		color = get_texel(data, x, y, slice);
		pixel_put_img(data->wrld, x, y, color);
		if (y > data->mlx->w_h)
			break ;
		y++;
	}
}

void	render_walls3d(t_data *data)
{
	int	slice;
	int	i;

	i = 0;
	while (i <= data->mlx->w_w - 1)
	{
		slice = ((double)UNIT / data->rays[i].dist) * data->dsp;
		render_slice(data, slice, i);
		i++;
	}
}

int	keyup(int keycode, t_data *data)
{
	if (keycode == 65361 || keycode == 65363)
		data->ply->r_dir = 0;
	if (keycode == 119 || keycode == 115)
		data->ply->mv_dir = 0;
	if (keycode == 97 || keycode == 100)
	{
		data->ply->d_dir = 0;
		data->ply->mh_dir = 0;
	}
	return (0);
}

void	get_m_dir(int keycode, t_data *data)
{
	if (keycode == 119)
	{
		data->ply->mv_dir = 1;
		return ;
	}
	if (keycode == 115)
	{
		data->ply->mv_dir = -1;
		return ;
	}
	if (keycode == 97)
	{
		data->ply->mh_dir = 1;
		data->ply->d_dir = -1;
	}
	if (keycode == 100)
	{
		data->ply->mh_dir = 1;
		data->ply->d_dir = 1;
	}
}

void	get_r_dir(int keycode, t_data *data)
{
	if (keycode == 65363)
	{
		data->ply->r_dir = -1;
		return ;
	}
	if (keycode == 65361)
	{
		data->ply->r_dir = 1;
		return ;
	}
}
