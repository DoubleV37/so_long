/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:38:23 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/23 17:07:10 by vviovi           ###   ########.fr       */
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

int	is_fill(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (map->map[y])
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

int	is_solvable(t_map *map)
{
	size_t	x;
	size_t	y;
	t_map	maptest;

	y = 0;
	x = 0;
	duplmap(&maptest, map);
	maptest.map[maptest.y_player][maptest.y_player] = 'V';
	while (!is_fill(&maptest))
	{
		x = 0;
		y = 0;
		while (maptest.map[y])
		{
			if (maptest.map[y][x] == 'V')
			{
				if (maptest.map[y - 1][x] && maptest.map[y - 1][x] != '1')
					maptest.map[y - 1][x] = 'V';
				if (maptest.map[y + 1][x] && maptest.map[y + 1][x] != '1')
					maptest.map[y + 1][x] = 'V';
				if (maptest.map[y][x - 1] && maptest.map[y][x - 1] != '1')
					maptest.map[y][x - 1] = 'V';
				if (maptest.map[y][x + 1] && maptest.map[y][x + 1] != '1')
					maptest.map[y][x + 1] = 'V';
			}
			if (x == maptest.size_x)
			{
				x = 0;
				y++;
			}
			x++;
		}
	}
	x = 0;
	y = 0;
	while (maptest.map[y])
	{
		if (maptest.map[y][x] == 'C' || maptest.map[y][x] == 'E')
		{
			free_map(&maptest.map);
			return (0);
		}
		if (x == maptest.size_x)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
	free_map(&maptest.map);
	return (1);
}

int	isvalid_map(t_vars *vars)
{
	size_t	nbstart;
	size_t	nbend;
	size_t	nbcollect;
	size_t	x;
	size_t	y;

	nbstart = 0;
	nbend = 0;
	nbcollect = 0;
	y = 0;
	while (vars->map.map[y])
	{
		x = 0;
		while (vars->map.map[y][x])
		{
			if ((y == 0 || y == vars->map.size_y - 1 || x == 0
					|| x == vars->map.size_x) && vars->map.map[y][x] != '1')
				return (0);
			else if (vars->map.map[y][x] == 'E')
			{
				vars->map.x_end = x;
				vars->map.y_end = y;
				nbend++;
			}
			else if (vars->map.map[y][x] == 'C')
				nbcollect++;
			else if (vars->map.map[y][x] == 'P')
			{
				vars->map.x_player = x;
				vars->map.y_player = y;
				nbstart++;
			}
			x++;
		}
		y++;
	}
	if (nbstart != 1 || nbend != 1 || nbcollect == 0
		|| !is_solvable(&vars->map))
		return (0);
	vars->map.nbcollec = nbcollect;
	return (1);
}
