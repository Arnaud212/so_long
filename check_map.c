/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:23:52 by agiraud           #+#    #+#             */
/*   Updated: 2021/11/15 16:06:03 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_composed(t_data *data, int r, int c)
{
	if (data->map.array[r][c] == PLAYER)
	{
		data->player.row = r;
		data->player.col = c;
		data->player.count++;
	}
	if (data->map.array[r][c] == COLLECTABLE)
		data->collectable.count++;
	if (data->map.array[r][c] == EXIT)
		data->exit_count++;
	if (!ft_strchr("01CPE", data->map.array[r][c]))
		ft_error("Invalid character in map.", data);
	if (r == 0 || r == data->map.rows - 1 || c == 0
		|| c == data->map.cols - 1)
		if (data->map.array[r][c] != WALL)
			ft_error("Map must be surrounded by walls.", data);
}

int	check_map(t_data *data)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	data->exit_count = 0;
	data->player.count = 0;
	data->collectable.count = 0;
	while (r < data->map.rows)
	{
		c = 0;
		while (c < data->map.cols)
		{
			check_map_composed(data, r, c);
			c++;
		}
		r++;
	}
	if (data->exit_count < 1 || data->player.count != 1
		|| data->collectable.count < 1)
		ft_error("Invalid map.", data);
	return (0);
}
