/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:25:10 by agiraud           #+#    #+#             */
/*   Updated: 2021/11/15 16:13:45 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_2tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
				free(tab[i]);
			i++;
		}
		free(tab);
	}
}

int	ft_error(char *str, t_data *data)
{
	if (str)
	{
		printf("Error\n%s\n", str);
		free_2tab(data->map.array);
		exit(EXIT_FAILURE);
	}
	else
	{
		free_2tab(data->map.array);
		exit(EXIT_SUCCESS);
	}
}

int	ft_close(t_data *data)
{
	free_2tab(data->map.array);
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

int	check_action(t_data *data, int row, int col)
{
	if (data->map.array[row][col] != WALL)
	{
		if (data->map.array[row][col] == COLLECTABLE)
		{
			data->collectable.count--;
			data->map.array[row][col] = EMPTY;
		}
		if (data->map.array[row][col] == EXIT)
		{
			if (data->collectable.count == 0)
			{
				printf("Moves: %d\nYou win!\n", ++data->move_count);
				ft_error(NULL, data);
			}
		}
		printf("Moves: %d\n", ++data->move_count);
		return (1);
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_FAILURE);
	}
	if (keycode == 13)
		if (check_action(data, data->player.row - 1, data->player.col))
			data->player.row -= 1;
	if (keycode == 0)
		if (check_action(data, data->player.row, data->player.col - 1))
			data->player.col -= 1;
	if (keycode == 1)
		if (check_action(data, data->player.row + 1, data->player.col))
			data->player.row += 1;
	if (keycode == 2)
		if (check_action(data, data->player.row, data->player.col + 1))
			data->player.col += 1;
	mlx_clear_window(data->mlx, data->win);
	create_screen(data);
	return (0);
}
