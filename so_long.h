/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:01:50 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 22:20:29 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "Get_Next_Line/get_next_line.h"
# include "libft/libft.h"
# include "Printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_map
{
	int		fd;
	int		len_map;
	int		row_map;
	int		col_map;
	int		max_coin;
	int		coin;
	int		moves;
	int		canopen;
	int		dead;
	int		win;
	int		move;
	int		animation_steve;
	int		animation_steve_left;
	int		animation_creeper;
	int		x_creeper;
	int		y_creeper;
	int		x_steve;
	int		y_steve;
	int		steve_right_left;
	char	*path;
	char	**map;
}				t_map;

typedef struct s_image
{
	void	*wall;
	void	*floor;
	void	*steve[4];
	void	*steve_left[4];
	void	*creeper[4];
	void	*door;
	void	*blackblock;
	void	*coin;
	void	*youwin;
	void	*gameover;
}				t_image;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_map		map;
	t_vector	img_position;
}				t_data;

int		ft_len_map(t_data *data);
void	ft_map_conv(char *path, t_data	*data);
int		ft_close(t_data *data);
int		ft_input(int key, t_data *data);
void	ft_img_init(t_data *data);
void	ft_check_map(t_data *data);
void	ft_print_black_block_numb(t_data *data);
void	ft_movement_up(t_data *data);
void	ft_movement_down(t_data *data);
void	ft_movement_left(t_data *data);
void	ft_movement_right(t_data *data);
void	ft_print_moves(t_data *data);
void	ft_check_map_c(t_data *data);
int		ft_close_gm(t_data *data);
int		ft_put_steve(t_data *data);
int		ft_put_steve_left(t_data *data);
int		ft_put_creeper(t_data *data);
int		ft_check_map_wrong(t_data *data);
void	ft_free_map(t_data *data);
int		ft_check_rectangular(t_data *data);
int		ft_check_walls_up(t_data *data);
int		ft_check_walls_left(t_data *data);
int		ft_check_walls_down(t_data *data);
int		ft_check_walls_right(t_data *data);
void	ft_character_coordinates(t_data *data, char **map);
char	**ft_map_converter_for_ffill(t_data *data, char **map);
void	ft_free_map_ffill(t_data *data, char **map);
char	**ft_alloc_map_ffill(t_data *data);
int		ft_check_coin(t_data *data, char **map);

#endif
