/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:24:20 by agiraud           #+#    #+#             */
/*   Updated: 2021/11/15 13:29:31 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_screen_2(t_data *data, int r, int c)
{
	while (r < data->map.rows)
	{
		c = 0;
		while (c < data->map.cols)
		{	
			mlx_put_image_to_window(data->mlx, data->win,
				data->floor, c * TILE_SIZE, r * TILE_SIZE);
			if (data->map.array[r][c] == WALL)
				 mlx_put_image_to_window(data->mlx, data->win,
					data->walls, c * TILE_SIZE, r * TILE_SIZE);
			else if (data->map.array[r][c] == COLLECTABLE)
				mlx_put_image_to_window(data->mlx, data->win,
					data->collectable.img, c * TILE_SIZE, r * TILE_SIZE);
			else if (data->map.array[r][c] == EXIT)
				mlx_put_image_to_window(data->mlx, data->win,
					data->exit_img, c * TILE_SIZE, r * TILE_SIZE);
			c++;
		}
		r++;
	}
	c = data->player.col;
	r = data->player.row;
	mlx_put_image_to_window(data->mlx, data->win,
		data->player.img, c * TILE_SIZE, r * TILE_SIZE);
}

int	create_screen(t_data *data)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	create_screen_2(data, r, c);
	return (0);
}
