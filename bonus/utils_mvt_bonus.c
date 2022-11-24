/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mvt_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:52:48 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/24 14:02:29 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

char	*get_nbmov(t_vars *vars)
{
	char	*linenbmov;
	char	*nbmov;

	nbmov = ft_itoa(vars->nbhit);
	linenbmov = ft_strjoin("Number of movement : ", nbmov);
	free(nbmov);
	return (linenbmov);
}
