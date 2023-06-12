/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:01:29 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 22:10:44 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize(t_data *data)
{
	data->map.coin = 0;
	data->map.moves = 0;
	data->map.dead = 0;
	data->map.win = 0;
	data->map.canopen = 0;
	data->map.animation_steve = 1;
	data->map.animation_steve_left = 1;
	data->map.animation_creeper = 1;
	data->map.steve_right_left = 0;
	data->map.move = 0;
}

void	ft_img_creeper(t_data *data)
{
	int	width;

	data->img.creeper[0] = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/Creeper1.xpm", &width, &width);
	data->img.creeper[1] = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/Creeper2.xpm", &width, &width);
	data->img.creeper[2] = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/Creeper3.xpm", &width, &width);
	data->img.creeper[3] = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/Creeper4.xpm", &width, &width);
}

void	ft_img_steve_left(t_data *data)
{
	int	width;

	data->img.steve_left[0] = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/steve1_left.xpm", &width, &width);
	data->img.steve_left[1] = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/steve2_left.xpm", &width, &width);
	data->img.steve_left[2] = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/steve3_left.xpm", &width, &width);
	data->img.steve_left[3] = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/steve4_left.xpm", &width, &width);
}

void	ft_img_steve(t_data *data)
{
	int	width;

	data->img.steve[0] = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/steve1.xpm", &width, &width);
	data->img.steve[1] = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/steve2.xpm", &width, &width);
	data->img.steve[2] = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/steve3.xpm", &width, &width);
	data->img.steve[3] = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/steve4.xpm", &width, &width);
}

void	ft_img_init(t_data *data)
{
	int	width;

	ft_initialize(data);
	data->img.wall = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/wall.xpm", &width, &width);
	data->img.floor = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/floor.xpm", &width, &width);
	ft_img_steve(data);
	ft_img_steve_left(data);
	ft_img_creeper(data);
	data->img.door = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/open.xpm", &width, &width);
	data->img.blackblock = mlx_xpm_file_to_image \
	(data->mlx, "./Textures/numbers.xpm", &width, &width);
	data->img.coin = mlx_xpm_file_to_image \
	(data->mlx, "Textures/coin.xpm", &width, &width);
	data->img.youwin = mlx_xpm_file_to_image \
	(data->mlx, "Textures/youwin.xpm", &width, &width);
	data->img.gameover = mlx_xpm_file_to_image \
	(data->mlx, "Textures/gameover.xpm", &width, &width);
}
