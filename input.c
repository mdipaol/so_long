/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:10:28 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 22:34:19 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open(t_data *data)
{
	int	width;

	if (data->map.coin == data->map.max_coin)
	{
		mlx_destroy_image(data->mlx, data->img.door);
		data->img.door = mlx_xpm_file_to_image \
		(data->mlx, "./Textures/close.xpm", &width, &width);
		data->map.coin++;
		data->map.canopen = 1;
		ft_printf("\033[5;7m\033[95m🔓 THE NETHER IS OPEN 🔓\n\033[0m");
	}
}

void	ft_space(t_data *data)
{
	ft_open(data);
	ft_check_map(data);
	ft_print_black_block_numb(data);
	ft_print_moves(data);
}

void	ft_win_or_dead(t_data *data)
{
	if (data->map.dead == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img.gameover, 0, 0);
		ft_printf("\n");
		ft_printf("\033[7m\033[32m💣💥 YOU BLOW UP 💥💣\n\033[0m");
		ft_printf("\033[31;7;5m⛔ Press ESC to quit ⛔\n\033[0m");
	}
	else if (data->map.win == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img.youwin, 0, 0);
		ft_printf("\n");
		ft_printf("\033[7m\033[33m🔥 YOU WIN 🔥\n\033[0m");
		ft_printf("\033[31;7;5m⛔ Press ESC to quit ⛔\n\033[0m");
	}
}

int	ft_input(int key, t_data *data)
{
	if (key == 65307)
		ft_close(data);
	if (data->map.dead == 0 && data->map.win == 0)
	{
		if (key == 119)
			ft_movement_up(data);
		if (key == 115)
			ft_movement_down(data);
		if (key == 97)
			ft_movement_left(data);
		if (key == 100)
			ft_movement_right(data);
		data->map.move = 1;
		ft_space(data);
		ft_printf("\033[7m\033[32m🚶Moves:%d🚶\r\033[0m", data->map.moves);
	}
	data->map.move = 0;
	if (data->map.dead == 1 || data->map.win == 1)
	{
		ft_win_or_dead(data);
		data->map.dead = 2;
		data->map.win = 2;
	}
	return (0);
}
