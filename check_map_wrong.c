/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wrong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:48:16 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 22:32:37 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	f_fill(t_data *data, char **map, int row, int col)
{
	if (map[row][col] == '1')
		return ;
	map[row][col] = '1';
	f_fill(data, map, row -1, col);
	f_fill(data, map, row +1, col);
	f_fill(data, map, row, col - 1);
	f_fill(data, map, row, col + 1);
}

int	ft_check_path(t_data *data)
{
	int		row;
	int		col;
	char	**map;
	int		coin;

	col = 0;
	coin = 0;
	map = ft_alloc_map_ffill(data);
	map = ft_map_converter_for_ffill(data, map);
	ft_character_coordinates(data, map);
	row = data->map.y_steve;
	col = data->map.x_steve;
	f_fill(data, map, row, col);
	row = 0;
	coin = ft_check_coin(data, map);
	ft_free_map_ffill(data, map);
	if (coin == -1)
		return (0);
	else
		return (1);
}

int	ft_check_p_c_e(t_data *data, int p, int c, int e)
{
	int	row;
	int	col;

	row = 0;
	while (data->map.map[row])
	{
		col = 0;
		while (data->map.map[row][col])
		{
			if (data->map.map[row][col] == 'P')
				p = 1;
			if (data->map.map[row][col] == 'C')
				c = 1;
			if (data->map.map[row][col] == 'E')
				e = 1;
			col++;
		}
		row++;
	}
	if (p == 0 || c == 0 || e == 0)
	{
		ft_printf("\033[7m\033[32m⛔ ERROR MAP | INCORRECT P, C OR E ⛔\n\033[0m");
		return (1);
	}
	return (0);
}

int	ft_check_walls(t_data *data)
{
	if (ft_check_walls_up(data) == 1)
		return (1);
	if (ft_check_walls_left(data) == 1)
		return (1);
	if (ft_check_walls_right(data) == 1)
		return (1);
	if (ft_check_walls_down(data) == 1)
		return (1);
	return (0);
}

int	ft_check_map_wrong(t_data *data)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	if (ft_check_walls(data) == 1)
		return (1);
	if (ft_check_p_c_e(data, p, c, e) == 1)
		return (1);
	if (ft_check_path(data) == 1)
	{
		ft_printf("\033[7m\033[32m⛔ | ERROR MAP | ⛔\n\033[0m");
		return (1);
	}
	return (0);
}
