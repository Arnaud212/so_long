/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:24:00 by agiraud           #+#    #+#             */
/*   Updated: 2021/11/15 16:10:47 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_is_rectangular(char *new_line, int expected_length)
{
	int	new_line_length;

	new_line_length = ft_strlen(new_line);
	if (ft_strchr(new_line, '\n'))
		new_line_length -= 1;
	return (new_line_length == expected_length);
}

static int	check_map_extension(char *map_path, t_data *data)
{
	size_t	path_length;
	char	*ber;

	path_length = ft_strlen(map_path);
	ber = ft_strnstr(map_path, ".ber", path_length);
	if (ber)
	{
		if (ber == (map_path + path_length - 4))
			return (1);
	}
	ft_error("Invalid extension <.ber>", data);
	return (0);
}

// Alloue de la mémoire et ajoute une ligne au tableau de la carte. 
// Met à jour le nombre de lignes.

static int	create_map(t_map *map, char *new_line, t_data *data)
{
	char	**new_map;
	size_t	i;

	i = 0;
	map->rows += 1;
	new_map = malloc(sizeof(char *) * (map->rows + 1));
	if (!new_map)
		ft_error("Error allocating memory for the new map.", data);
	while (map->array[i])
	{
		new_map[i] = map->array[i];
		i++;
	}
	new_map[i] = new_line;
	new_map[i + 1] = NULL;
	free(map->array);
	map->array = new_map;
	return (0);
}

// Lis le fichier de la carte une ligne à la fois et l'enregistre.

int	read_map(char *map_path, t_map *map, t_data *data)
{
	int		fd;
	char	*new_line;

	check_map_extension(map_path, data);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error("Couldn't open map file.", data);
	new_line = get_next_line(fd);
	if (!new_line)
		ft_error("Failed to read map file.", data);
	map->cols = ft_strlen(new_line) - 1;
	while (new_line)
	{
		if (!map_is_rectangular(new_line, map->cols))
			ft_error("Map must be rectangular", data);
		create_map(map, new_line, data);
		new_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
