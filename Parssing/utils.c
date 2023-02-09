/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 02:12:54 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/09 02:13:59 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_read_map(t_map *t, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	t->fd = open(av[1], O_RDWR);
	if (t->fd < 0)
	{
		printf("\033[0;31mfile not found !!\n");
		exit(1);
	}
	t->tab = get_next_line(t->fd);
	while (t->tab)
	{
		free(t->tab);
		t->tab = get_next_line(t->fd);
		i++;
	}
	t->map_height = i;
	t->all_map2d = (char **)malloc((i + 1) * sizeof(char *));
	if (!t->all_map2d)
		return ;
	j = 0;
	close(t->fd);
	t->fd = open(av[1], O_RDWR);
	t->all_map2d[j] = get_next_line(t->fd);
	while (j < i)
	{
		j++;
		t->all_map2d[j] = get_next_line(t->fd);
	}
	t->all_map2d[j] = NULL;
}

int	get_width(char **str)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		len = ft_strlen(str[i]);
		if (j < len)
		{
			j = len;
			i++;
		}
		else
			i++;
	}
	return (j);
}

int	get_height(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
