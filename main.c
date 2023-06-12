
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:59:02 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 20:02:29 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		data.mlx = mlx_init();
		ft_map_conv(argv[1], &data);
		if (ft_check_map_wrong(&data) == 1)
			return (0);
		ft_img_init(&data);
		ft_check_map_c(&data);
		data.win = mlx_new_window \
		(data.mlx, data.map.col_map * (50), data.map.row_map * (50), "SO_LONG");
		ft_check_map(&data);
		mlx_key_hook(data.win, ft_input, &data);
		mlx_hook(data.win, 17, 0, ft_close, &data);
		mlx_loop_hook(data.mlx, *ft_put_steve, &data);
		if (!(data.map.dead == 2 || data.map.win == 2))
			mlx_loop(data.mlx);
	}
}
