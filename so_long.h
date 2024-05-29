/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:25:07 by agiraud           #+#    #+#             */
/*   Updated: 2024/05/29 19:05:47 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

# define TILE_SIZE	32

typedef enum e_tiletype {
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}				t_tiletype;

typedef struct s_map {
	char	**array;
	int		rows;
	int		cols;
}				t_map;

typedef struct s_player
{
	void	*img;
	int		row;
	int		col;
	int		count;
}				t_player;

typedef struct s_collectable {
	void	*img;
	int		count;
}				t_collectable;

typedef struct s_data {
	void			*mlx;
	void			*win;
	t_player		player;
	void			*floor;
	void			*walls;
	t_collectable	collectable;
	void			*exit_img;
	int				exit_count;
	int				move_count;
	t_map			map;
}				t_data;

int	key_hook(int keycode, t_data *data);
int	ft_error(char *str, t_data *data);
int	ft_close(t_data *data);
int	read_map(char *map_path, t_map *map, t_data *data);
int	check_map(t_data *data);
int	create_screen(t_data *data);
int	load_assets(t_data *data);

#endif
