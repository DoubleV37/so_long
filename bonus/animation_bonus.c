/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:07:33 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/28 17:06:17 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animation_wall(t_vars *vars)
{
	size_t	x;
	size_t	y;

	if (vars->nbturn == 10000)
	{
		vars->nbturn = 0;
		y = 0;
		vars->nbwalltyp += 1;
		while (vars->map.map[y])
		{
			x = 0;
			while (vars->map.map[y][x])
			{
				if (vars->map.map[y][x] == '1' && x % 2 == 1 && y % 2 == 1)
				{
					if (vars->nbwalltyp > 17)
						vars->nbwalltyp = 10;
					mlx_put_image_to_window(vars->mlx, vars->win,
						vars->assets[vars->nbwalltyp], x * 32, y * 32 + 32);
				}
				x++;
			}
			y++;
		}
	}
	else
		vars->nbturn++;
	return (0);
}
