/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:31:17 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 20:00:42 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map_ffill(t_data *data, char **map)
{
	int	row;

	row = 0;
	while (row <= data->map.len_map)
	{
		free(map[row]);
		row++;
	}
	free(map);
}

char	**ft_map_converter_for_ffill(t_data *data, char **map)
{
	int	row;
	int	col;

	row = 0;
	while (data->map.map[row])
	{
		col = 0;
		while (data->map.map[row][col])
		{
			map[row][col] = data->map.map[row][col];
			col++;
		}
		row++;
	}
	return (map);
}

void	ft_character_coordinates(t_data *data, char **map)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->map.len_map)
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'P')
			{
				data->map.x_steve = col;
				data->map.y_steve = row;
			}
			col++;
		}
		row++;
	}
}
