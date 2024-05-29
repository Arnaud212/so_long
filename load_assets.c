/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:24:56 by agiraud           #+#    #+#             */
/*   Updated: 2021/11/15 16:11:49 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_floor_wall(t_data *data)
{
	int		width;
	int		height;

	data->floor = mlx_xpm_file_to_image(data->mlx,
			"./textures/background.xpm", &width, &height);
	if (!data->floor)
		ft_error("Failed to load floor sprite.", data);
	data->walls = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &width, &height);
	if (!data->walls)
		ft_error("Failed to load wall sprite.", data);
}

static void	load_player(t_data *data)
{
	int		width;
	int		height;

	data->player.img = mlx_xpm_file_to_image(data->mlx,
			"./textures/player.xpm", &width, &height);
	if (!data->player.img)
		ft_error("Failed to load character sprite.", data);
}

static void	load_collectable(t_data *data)
{
	int		width;
	int		height;

	data->collectable.img = mlx_xpm_file_to_image(data->mlx,
			"./textures/collectable.xpm", &width, &height);
	if (!data->collectable.img)
		ft_error("Failed to load collectable sprite.", data);
}

static void	load_exit(t_data *data)
{
	int		width;
	int		height;

	data->exit_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit.xpm", &width, &height);
	if (!data->player.img)
		ft_error("Failed to load exit sprite.", data);
}

int	load_assets(t_data *data)
{
	load_floor_wall(data);
	load_player(data);
	load_collectable(data);
	load_exit(data);
	return (0);
}
