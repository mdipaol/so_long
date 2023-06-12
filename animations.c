/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:24:15 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 22:21:54 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_put_creeper(t_data *data)
{
	int			columns;
	int			row;
	static int	i = 0;

	columns = data->map.x_creeper;
	row = data->map.y_creeper;
	if ((data->map.win != 2 || data->map.dead != 2) && \
	(data->map.animation_creeper % 20000 == 0 || data->map.move == 1))
	{
		usleep(20000);
		if (i == 3)
			i = 0;
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img.creeper[i], columns * 50, row * 50);
		i++;
	}
	data->map.animation_creeper++;
	return (0);
}

int	ft_put_steve_left(t_data *data)
{
	int			columns;
	int			row;
	static int	i = 0;

	columns = data->img_position.x;
	row = data->img_position.y;
	if ((data->map.win != 2 || data->map.dead != 2) && \
	(data->map.animation_steve_left % 20000 == 0 || data->map.move == 1))
	{
		usleep(20000);
		if (i == 3)
			i = 0;
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img.steve_left[i], columns * 50, row * 50);
		i++;
	}
	data->map.animation_steve_left++;
	return (0);
}

int	ft_put_steve(t_data *data)
{
	int			columns;
	int			row;
	static int	i = 0;

	columns = data->img_position.x;
	row = data->img_position.y;
	if (data->map.steve_right_left == 1)
		ft_put_steve_left(data);
	else if ((data->map.win != 2 || data->map.dead != 2) \
	&& (data->map.animation_steve % 20000 == 0 || data->map.move == 1))
	{
		usleep(20000);
		if (i == 3)
			i = 0;
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img.steve[i], columns * 50, row * 50);
		i++;
	}
	ft_put_creeper(data);
	data->map.animation_steve++;
	return (0);
}

char	**ft_alloc_map_ffill(t_data *data)
{
	int		len;
	int		col;
	char	**map;

	col = 0;
	len = data->map.len_map;
	map = ft_calloc(sizeof (char *), (len + 1));
	while (col <= data->map.len_map)
	{
		map[col] = ft_calloc(sizeof (char), (data->map.col_map + 2));
		col++;
	}
	return (map);
}

int	ft_check_coin(t_data *data, char **map)
{
	int	row;
	int	col;
	int	coin;

	row = 0;
	col = 0;
	coin = 0;
	while (data->map.map[row] && map[row])
	{
		col = 0;
		while (data->map.map[row][col] && map[row][col])
		{
			if (map[row][col] == 'C')
				coin++;
			if (data->map.map[row][col] == 'E' && map[row][col] == '1')
				coin--;
			col++;
		}
		row++;
	}
	return (coin);
}
