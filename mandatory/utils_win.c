/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:50:35 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/24 13:32:25 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	endgame(t_vars *vars)
{
	close_window(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		close_window(vars);
	else if (keycode == XK_w || keycode == XK_Up)
		moveplayer_up(vars);
	else if (keycode == XK_s || keycode == XK_Down)
		moveplayer_down(vars);
	else if (keycode == XK_a || keycode == XK_Left)
		moveplayer_left(vars);
	else if (keycode == XK_d || keycode == XK_Right)
		moveplayer_right(vars);
	return (0);
}

void	put_image_win(t_vars *vars, size_t x, size_t y)
{
	if (vars->map.map[y][x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[0], x * 32, y * 32);
	else if (vars->map.map[y][x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[8], x * 32, y * 32);
	else if (vars->map.map[y][x] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[3], x * 32, y * 32);
	else if (vars->map.map[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[9], x * 32, y * 32);
	else
	{
		if (x % 2 == 0)
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->assets[1], x * 32, y * 32);
		else
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->assets[2], x * 32, y * 32);
	}
}

void	buildstart(t_vars *vars)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (vars->map.map[y] && y < vars->map.size_y)
	{
		x = 0;
		while (vars->map.map[y][x] && x < vars->map.size_x)
		{
			put_image_win(vars, x, y);
			x++;
		}
		y++;
	}
}

void	init_vars_and_win(t_vars *vars)
{
	vars->nbhit = 0;
	vars->nbcollget = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (vars->map.size_x * 32),
			(vars->map.size_y * 32), "Star Citizen 1.0");
	set_assets(vars);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, StructureNotifyMask, close_window, vars);
}
