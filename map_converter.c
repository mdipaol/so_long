/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:13:02 by mdi-paol          #+#    #+#             */
/*   Updated: 2023/01/19 22:34:46 by mdi-paol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len_map(t_data *data)
{
	char	*s;
	int		len;
	int		fd;

	s = 0;
	len = 0;
	data->map.len_map = 0;
	fd = open(data->map.path, O_RDONLY);
	while (s || len == 0)
	{
		s = get_next_line(fd);
		free(s);
		len++;
	}
	len = len - 1;
	data->map.len_map = len;
	close(fd);
	free(s);
	return (len);
}

void	ft_map_conv(char *path, t_data	*data)
{
	int	fd;
	int	row;
	int	len;

	row = 0;
	data->map.path = path;
	len = ft_len_map(data);
	data->map.map = ft_calloc(sizeof (char *), (len + 1));
	fd = open (path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("\033[31;7;5m⛔ Insert Correct MAP ⛔\n\033[0m");
		exit(1);
	}
	while (row < len)
	{
		data->map.map[row] = get_next_line(fd);
		row++;
	}
	data->map.row_map = row;
	data->map.col_map = ft_strlen(data->map.map[0]) - 1;
	close (fd);
}
