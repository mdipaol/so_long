/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:49:35 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 22:31:42 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_walls_up(t_data *data)
{
	int	col;

	col = 0;
	while (data->map.map[0][col])
	{
		if (data->map.map[0][col] != '1' && \
		data->map.map[0][col] != '\n' && data->map.map[0][col])
		{
			ft_printf("\033[7m\033[32m⛔ ERROR MAP | INCORRECT WALLS ⛔\n\033[0m");
			return (1);
		}
		col++;
	}
	return (0);
}

int	ft_check_walls_left(t_data *data)
{
	int	row;

	row = 0;
	while (row < data->map.row_map)
	{
		if (data->map.map[row][0] != '1' && data->map.map[row][0])
		{
			ft_printf("\033[7m\033[32m⛔ ERROR MAP | INCORRECT WALLS ⛔\n\033[0m");
			return (1);
		}
		row++;
	}
	return (0);
}

int	ft_check_walls_right(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	col = data->map.col_map - 1;
	while (row < data->map.row_map)
	{
		if (data->map.map[row][col] \
		!= '1' && data->map.map[row][col])
		{
			ft_printf("\033[7m\033[32m⛔ ERROR MAP | INCORRECT WALLS ⛔\n\033[0m");
			return (1);
		}
		row++;
	}
	return (0);
}

int	ft_check_walls_down(t_data *data)
{
	int	col;
	int	row;

	col = 0;
	row = data->map.row_map - 1;
	while (col < data->map.col_map)
	{
		if (data->map.map[row][col] != '1' \
		&& data->map.map[row][col] != '\n' && data->map.map[row][col])
		{
			ft_printf("\033[7m\033[32m⛔ ERROR MAP | INCORRECT WALLS ⛔\n\033[0m");
			return (1);
		}
		col++;
	}
	return (0);
}
