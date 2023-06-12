/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:50:17 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 22:28:10 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_2(t_data *data, int row, int columns)
{
	if (data->map.map[row][columns] == 'E')
		mlx_put_image_to_window \
		(data->mlx, data->win, data->img.door, columns * 50, row * 50);
	if (data->map.map[row][columns] == 'P')
	{
		data->img_position.x = columns;
		data->img_position.y = row;
		ft_put_steve(data);
	}
	if (data->map.map[row][columns] == 'H')
	{
		data->map.x_creeper = columns;
		data->map.y_creeper = row;
		ft_put_creeper(data);
	}
}

void	ft_check_map(t_data *data)
{
	int	row;
	int	columns;

	row = 0;
	while (data->map.map[row])
	{
		columns = 0;
		while (data->map.map[row][columns])
		{
			if (data->map.map[row][columns] == '1')
				mlx_put_image_to_window \
				(data->mlx, data->win, data->img.wall, columns * 50, row * 50);
			if (data->map.map[row][columns] == '0')
				mlx_put_image_to_window \
				(data->mlx, data->win, data->img.floor, columns * 50, row * 50);
			if (data->map.map[row][columns] == 'C')
				mlx_put_image_to_window \
				(data->mlx, data->win, data->img.coin, columns * 50, row * 50);
			ft_check_map_2(data, row, columns);
			columns++;
		}
		row++;
	}
}

void	ft_check_map_c(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	data->map.max_coin = 0;
	while (data->map.map[row])
	{
		col = 0;
		while (data->map.map[row][col])
		{
			if (data->map.map[row][col] == 'C')
				data->map.max_coin++;
			col++;
		}
		row++;
	}
}

void	ft_print_black_block_numb(t_data *data)
{
	int	row;
	int	columns;

	row = 0;
	columns = 0;
	while (data->map.map[row][columns])
		columns++;
	columns = columns - 2;
	mlx_put_image_to_window \
	(data->mlx, data->win, data->img.blackblock, columns * 50, 0);
}

void	ft_print_moves(t_data *data)
{
	int		row;
	int		columns;
	char	*s;

	row = 0;
	columns = 0;
	s = ft_itoa(data->map.moves);
	while (data->map.map[row][columns])
		columns++;
	columns = columns - 2;
	mlx_string_put(data->mlx, data->win, columns * 50 + 20, 14, 0xFF0000, s);
	free(s);
}
