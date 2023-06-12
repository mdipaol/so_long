/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:11:12 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 22:34:49 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_movement_up(t_data *data)
{
	int	row;
	int	col;

	row = data->img_position.y;
	col = data->img_position.x;
	if (data->map.map[row - 1][col] != '1')
	{
		if (data->map.map[row - 1][col] == 'C')
			data->map.coin = data->map.coin + 1;
		if (data->map.map[row - 1][col] == 'H')
			data->map.dead = 1;
		if (data->map.map[row - 1][col] == 'E' && data->map.canopen)
			data->map.win = 1;
		data->map.map[row][col] = '0';
		data->map.map[row - 1][col] = 'P';
		data->map.moves++;
	}
}

void	ft_movement_down(t_data *data)
{
	int	row;
	int	col;

	row = data->img_position.y;
	col = data->img_position.x;
	if (data->map.map[row + 1][col] != '1')
	{
		if (data->map.map[row + 1][col] == 'C')
			data->map.coin = data->map.coin + 1;
		if (data->map.map[row + 1][col] == 'H')
			data->map.dead = 1;
		if (data->map.map[row + 1][col] == 'E' && data->map.canopen)
			data->map.win = 1;
		data->map.map[row][col] = '0';
		data->map.map[row + 1][col] = 'P';
		data->map.moves++;
	}
}

void	ft_movement_left(t_data *data)
{
	int	row;
	int	col;

	row = data->img_position.y;
	col = data->img_position.x;
	if (data->map.map[row][col - 1] != '1')
	{
		if (data->map.map[row][col - 1] == 'C')
			data->map.coin = data->map.coin + 1;
		if (data->map.map[row][col - 1] == 'H')
			data->map.dead = 1;
		if (data->map.map[row][col - 1] == 'E' && data->map.canopen)
			data->map.win = 1;
		if (!(data->map.map[row][col - 1] == 'E' && !data->map.canopen))
		{
			data->map.map[row][col] = '0';
			data->map.map[row][col - 1] = 'P';
			data->map.moves++;
		}
	}
	data->map.steve_right_left = 1;
}

void	ft_movement_right(t_data *data)
{
	int	row;
	int	col;

	row = data->img_position.y;
	col = data->img_position.x;
	if (data->map.map[row][col + 1] != '1')
	{
		if (data->map.map[row][col + 1] == 'C')
			data->map.coin = data->map.coin + 1;
		if (data->map.map[row][col + 1] == 'H')
			data->map.dead = 1;
		if (data->map.map[row][col + 1] == 'E' && data->map.canopen)
			data->map.win = 1;
		data->map.map[row][col] = '0';
		data->map.map[row][col + 1] = 'P';
		data->map.moves++;
	}
	data->map.steve_right_left = 0;
}
