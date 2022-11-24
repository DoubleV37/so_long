/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mvt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:52:48 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/24 13:28:24 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	searchpos(t_vars *vars, size_t pos_x, size_t pos_y)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (vars->map.map[y])
	{
		x = 0;
		while (vars->map.map[y][x])
		{
			if (pos_x == x && pos_y == y)
				return (vars->map.map[y][x]);
			x++;
		}
		y++;
	}
	return ('\0');
}
