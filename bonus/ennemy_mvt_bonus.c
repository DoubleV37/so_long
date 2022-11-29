/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_mvt_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:21:41 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/29 15:23:38 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	moveennemy_up(t_vars *vars, size_t pos_x, size_t pos_y)
{
	char	futurpos;

	futurpos = searchpos(vars, pos_x, pos_y - 1);
	if (!futurpos || futurpos == '1' || futurpos == 'C' || futurpos == 'A')
		return ;
	else if (vars->map.x_player == pos_x && vars->map.y_player == pos_y - 1)
		endgame(vars, 0);
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[0], pos_x * 32, pos_y * 32 + 32);
		if (pos_x == vars->map.x_end && vars->map.y_end == pos_y)
			place_rightend(vars, pos_x, pos_y);
		vars->map.map[pos_y][pos_x] = '0';
		pos_y--;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[18], pos_x * 32, pos_y * 32 + 32);
		vars->map.map[pos_y][pos_x] = 'A';
	}
}

void	moveennemy_down(t_vars *vars, size_t pos_x, size_t pos_y)
{
	char	futurpos;

	futurpos = searchpos(vars, pos_x, pos_y + 1);
	if (!futurpos || futurpos == '1' || futurpos == 'C' || futurpos == 'A')
		return ;
	else if (vars->map.x_player == pos_x && vars->map.y_player == pos_y + 1)
		endgame(vars, 0);
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[0], pos_x * 32, pos_y * 32 + 32);
		if (pos_x == vars->map.x_end && vars->map.y_end == pos_y)
			place_rightend(vars, pos_x, pos_y);
		vars->map.map[pos_y][pos_x] = '0';
		pos_y++;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[19], pos_x * 32, pos_y * 32 + 32);
		vars->map.map[pos_y][pos_x] = 'A';
	}
}

void	moveennemy_left(t_vars *vars, size_t pos_x, size_t pos_y)
{
	char	futurpos;

	futurpos = searchpos(vars, pos_x - 1, pos_y);
	if (!futurpos || futurpos == '1' || futurpos == 'C' || futurpos == 'A')
		return ;
	else if (vars->map.x_player == pos_x - 1 && vars->map.y_player == pos_y)
		endgame(vars, 0);
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[0], pos_x * 32, pos_y * 32 + 32);
		if (pos_x == vars->map.x_end && vars->map.y_end == pos_y)
			place_rightend(vars, pos_x, pos_y);
		vars->map.map[pos_y][pos_x] = '0';
		pos_x--;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[20], pos_x * 32, pos_y * 32 + 32);
		vars->map.map[pos_y][pos_x] = 'A';
	}
}

void	moveennemy_right(t_vars *vars, size_t pos_x, size_t pos_y)
{
	char	futurpos;

	futurpos = searchpos(vars, pos_x + 1, pos_y);
	if (!futurpos || futurpos == '1' || futurpos == 'C' || futurpos == 'A')
		return ;
	else if (vars->map.x_player == pos_x + 1 && vars->map.y_player == pos_y)
		endgame(vars, 0);
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[0], pos_x * 32, pos_y * 32 + 32);
		if (pos_x == vars->map.x_end && vars->map.y_end == pos_y)
			place_rightend(vars, pos_x, pos_y);
		vars->map.map[pos_y][pos_x] = '0';
		pos_x++;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[21], pos_x * 32, pos_y * 32 + 32);
		vars->map.map[pos_y][pos_x] = 'A';
	}
}

void	move_ennemy(t_vars *vars, size_t x, size_t y)
{
	int	i;

	i = rand() % 5;
	if (i == 0)
		moveennemy_up(vars, x, y);
	else if (i == 1)
		moveennemy_down(vars, x, y);
	else if (i == 2)
		moveennemy_left(vars, x, y);
	else if (i == 3)
		moveennemy_right(vars, x, y);
	else
		return ;
}
