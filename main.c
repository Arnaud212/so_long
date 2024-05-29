/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:25:00 by agiraud           #+#    #+#             */
/*   Updated: 2024/05/29 19:27:41 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	games_init(t_data *data)
{
	data->move_count = 0;
	data->map.array = malloc(sizeof(char *));
	if (!data->map.array)
		ft_error("Error allocating memory for map array", data);
	data->map.array[0] = NULL;
	data->map.rows = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error("One argument with the .ber extension", &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_error("Mlx initialization failed", &data);
	games_init(&data);
	read_map(av[1], &(data.map), &data);
	check_map(&data);
	load_assets(&data);
	data.win = mlx_new_window(data.mlx, data.map.cols * TILE_SIZE,
			data.map.rows * TILE_SIZE, "so_long");
	if (!data.win)
		ft_error("Mlx couldn't create a new window.", &data);
	create_screen(&data);
	//mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 2, 1L<<0, key_hook, &data);
	mlx_hook(data.win, 17, (1L << 17), ft_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
