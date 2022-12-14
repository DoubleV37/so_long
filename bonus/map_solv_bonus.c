/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solv_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:20:14 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/30 14:47:23 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	maptest_gen(t_map *maptest, size_t x, size_t y)
{
	if (maptest->map[y][x] == 'V')
	{
		if (maptest->map[y - 1][x] && maptest->map[y - 1][x] != '1')
			maptest->map[y - 1][x] = 'V';
		if (maptest->map[y + 1][x] && maptest->map[y + 1][x] != '1')
			maptest->map[y + 1][x] = 'V';
		if (maptest->map[y][x - 1] && maptest->map[y][x - 1] != '1')
			maptest->map[y][x - 1] = 'V';
		if (maptest->map[y][x + 1] && maptest->map[y][x + 1] != '1')
			maptest->map[y][x + 1] = 'V';
	}
}

int	is_ennemy(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'A')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	is_corridor_imp(t_map *map)
{
	if (map->size_x == 3)
	{
		if (map->map[1][1] == 'E' || map->map[map->size_y - 2][1] == 'E')
			if (is_ennemy(map))
				return (1);
	}
	else if (map->size_y == 3)
	{
		if (map->map[1][1] == 'E' || map->map[1][map->size_x - 2] == 'E')
			if (is_ennemy(map))
				return (1);
	}
	return (0);
}

static int	is_validmap(t_map *maptest)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (maptest->map[y])
	{
		if (maptest->map[y][x] == 'C' || maptest->map[y][x] == 'E')
		{
			free_map(&maptest->map);
			return (0);
		}
		if (x == maptest->size_x)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
	return (1);
}

int	is_solvable(t_map *map)
{
	size_t	x;
	size_t	y;
	t_map	maptest;

	duplmap(&maptest, map);
	maptest.map[maptest.y_player][maptest.y_player] = 'V';
	while (!is_fill(&maptest))
	{
		x = 0;
		y = 0;
		while (maptest.map[y])
		{
			maptest_gen(&maptest, x, y);
			if (x == maptest.size_x)
			{
				x = 0;
				y++;
			}
			x++;
		}
	}
	if (!is_validmap(&maptest))
		return (0);
	free_map(&maptest.map);
	return (1);
}
