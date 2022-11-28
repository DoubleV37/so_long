/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_win_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:50:35 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/28 17:16:16 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	void	*asset;

	if (vars->map.map[y][x] == '0')
		asset = vars->assets[0];
	else if (vars->map.map[y][x] == 'E')
		asset = vars->assets[8];
	else if (vars->map.map[y][x] == 'P')
		asset = vars->assets[3];
	else if (vars->map.map[y][x] == 'C')
		asset = vars->assets[9];
	else if (vars->map.map[y][x] == 'A')
		asset = vars->assets[18];
	else
	{
		if (x % 2 == 0)
			asset = vars->assets[1];
		else if (y % 2 == 0)
			asset = vars->assets[2];
		else
			asset = vars->assets[10];
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
		asset, x * 32, y * 32 + 32);
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
	char	*nbmov;

	vars->nbhit = 0;
	vars->nbcollget = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (vars->map.size_x * 32),
			(vars->map.size_y * 32 + 32), "Star Citizen 1.0");
	nbmov = get_nbmov(vars);
	mlx_string_put(vars->mlx, vars->win, 5, 16, 0x00ff0000, nbmov);
	free(nbmov);
	set_assets(vars);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, StructureNotifyMask, close_window, vars);
}
