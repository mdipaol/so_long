/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:10:20 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 22:34:52 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_data *data)
{
	int	row;

	row = 0;
	while (data->map.map[row])
	{
		free(data->map.map[row]);
		row++;
	}
	free(data->map.map);
}

void	ft_destroy_creeper(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.creeper[0]);
	mlx_destroy_image(data->mlx, data->img.creeper[1]);
	mlx_destroy_image(data->mlx, data->img.creeper[2]);
	mlx_destroy_image(data->mlx, data->img.creeper[3]);
}

void	ft_destroy_steve(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.steve[0]);
	mlx_destroy_image(data->mlx, data->img.steve[1]);
	mlx_destroy_image(data->mlx, data->img.steve[2]);
	mlx_destroy_image(data->mlx, data->img.steve[3]);
}

void	ft_destroy_steve_left(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.steve_left[0]);
	mlx_destroy_image(data->mlx, data->img.steve_left[1]);
	mlx_destroy_image(data->mlx, data->img.steve_left[2]);
	mlx_destroy_image(data->mlx, data->img.steve_left[3]);
}

int	ft_close(t_data *data)
{
	ft_free_map(data);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.floor);
	ft_destroy_steve(data);
	ft_destroy_creeper(data);
	ft_destroy_steve_left(data);
	mlx_destroy_image(data->mlx, data->img.door);
	mlx_destroy_image(data->mlx, data->img.blackblock);
	mlx_destroy_image(data->mlx, data->img.coin);
	mlx_destroy_image(data->mlx, data->img.youwin);
	mlx_destroy_image(data->mlx, data->img.gameover);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
	return (0);
}
