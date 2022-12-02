/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:57:28 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/02 10:58:17 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_invalid_contentmap(t_vars *vars, size_t x, size_t *y)
{
	if ((*y == 0 || *y == vars->map.size_y - 1 || x == 0
			|| x == vars->map.size_x - 1) && vars->map.map[*y][x] != '1')
		return (1);
	else if (vars->map.map[*y][x] != '0' && vars->map.map[*y][x] != '1'
		&& vars->map.map[*y][x] != 'E' && vars->map.map[*y][x] != 'P'
		&& vars->map.map[*y][x] != 'C')
		return (1);
	else
		return (0);
}
