/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:38:23 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/02 10:48:57 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	len_line_map_isvalid(char **map)
{
	size_t	i;
	size_t	lenline;

	if (!map[0])
		return (0);
	i = 1;
	lenline = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != lenline)
			return (0);
		i++;
	}
	return (lenline);
}

int	verif_fillmap(t_map *map, size_t x, size_t y)
{
	if (map->map[y][x] == 'V')
	{
		if (map->map[y - 1][x] && map->map[y - 1][x] != '1'
			&& map->map[y - 1][x] != 'V')
			return (0);
		if (map->map[y + 1][x] && map->map[y + 1][x] != '1'
			&& map->map[y + 1][x] != 'V')
			return (0);
		if (map->map[y][x - 1] && map->map[y][x - 1] != '1'
			&& map->map[y][x - 1] != 'V')
			return (0);
		if (map->map[y][x + 1] && map->map[y][x + 1] != '1'
			&& map->map[y][x + 1] != 'V')
			return (0);
	}
	return (1);
}

int	is_fill(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (map->map[y])
	{
		if (!verif_fillmap(map, x, y))
			return (0);
		if (x == map->size_x)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
	return (1);
}

void	duplmap(t_map *dest, t_map *src)
{
	int	i;

	dest->nbcollec = src->nbcollec;
	dest->size_x = src->size_x;
	dest->size_y = src->size_y;
	dest->x_end = src->x_end;
	dest->y_end = src->y_end;
	dest->x_player = src->x_player;
	dest->y_player = src->y_player;
	dest->map = malloc(sizeof(char *) * (dest->size_y + 1));
	i = 0;
	while (src->map[i])
	{
		dest->map[i] = ft_strdup(src->map[i]);
		i++;
	}
	dest->map[i] = NULL;
}

int	isvalid_map(t_vars *vars)
{
	int		nbstart;
	int		nbend;
	size_t	y;

	nbstart = 0;
	nbend = 0;
	y = 0;
	vars->map.nbcollec = 0;
	while (vars->map.map[y])
	{
		if (!cpt_contentmap(vars, &nbstart, &nbend, &y))
			return (0);
		y++;
	}
	if (nbstart != 1 || nbend != 1 || vars->map.nbcollec == 0
		|| !is_solvable(&vars->map))
		return (0);
	return (1);
}
