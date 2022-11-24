/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvt_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:21:41 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/24 14:02:19 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	specialcase(t_vars *vars, size_t next_x, size_t next_y)
{
	char	*nbmov;

	nbmov = get_nbmov(vars);
	mlx_string_put(vars->mlx, vars->win, 5, 16, 0x00000000, nbmov);
	free(nbmov);
	vars->nbhit++;
	nbmov = get_nbmov(vars);
	mlx_string_put(vars->mlx, vars->win, 5, 16, 0x00ff0000, nbmov);
	free(nbmov);
	ctrl_end(vars);
	if (searchpos(vars, next_x, next_y) == 'C')
	{
		modifmap(vars, next_x, next_y, '0');
		vars->nbcollget++;
	}
	if (vars->map.nbcollec == vars->nbcollget)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[7], vars->map.x_end * 32, vars->map.y_end * 32 + 32);
		if (vars->map.x_end == next_x && vars->map.y_end == next_y)
			endgame(vars);
	}
}

void	moveplayer_up(t_vars *vars)
{
	char	futurpos;
	size_t	pos_x;
	size_t	pos_y;

	pos_x = vars->map.x_player;
	pos_y = vars->map.y_player;
	futurpos = searchpos(vars, pos_x, pos_y - 1);
	if (!futurpos || futurpos == '1')
		return ;
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[0], pos_x * 32, pos_y * 32 + 32);
		pos_y--;
		specialcase(vars, pos_x, pos_y);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[3], pos_x * 32, pos_y * 32 + 32);
		vars->map.y_player = pos_y;
		ft_printf("Number of movement : %i\n", vars->nbhit);
	}
}

void	moveplayer_down(t_vars *vars)
{
	char	futurpos;
	size_t	pos_x;
	size_t	pos_y;

	pos_x = vars->map.x_player;
	pos_y = vars->map.y_player;
	futurpos = searchpos(vars, pos_x, pos_y + 1);
	if (!futurpos || futurpos == '1')
		return ;
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[0], pos_x * 32, pos_y * 32 + 32);
		pos_y++;
		specialcase(vars, pos_x, pos_y);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[4], pos_x * 32, pos_y * 32 + 32);
		vars->map.y_player = pos_y;
		ft_printf("Number of movement : %i\n", vars->nbhit);
	}
}

void	moveplayer_left(t_vars *vars)
{
	char	futurpos;
	size_t	pos_x;
	size_t	pos_y;

	pos_x = vars->map.x_player;
	pos_y = vars->map.y_player;
	futurpos = searchpos(vars, pos_x - 1, pos_y);
	if (!futurpos || futurpos == '1')
		return ;
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[0], pos_x * 32, pos_y * 32 + 32);
		pos_x--;
		specialcase(vars, pos_x, pos_y);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[5], pos_x * 32, pos_y * 32 + 32);
		vars->map.x_player = pos_x;
		ft_printf("Number of movement : %i\n", vars->nbhit);
	}
}

void	moveplayer_right(t_vars *vars)
{
	char	futurpos;
	size_t	pos_x;
	size_t	pos_y;

	pos_x = vars->map.x_player;
	pos_y = vars->map.y_player;
	futurpos = searchpos(vars, pos_x + 1, pos_y);
	if (!futurpos || futurpos == '1')
		return ;
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[0], pos_x * 32, pos_y * 32 + 32);
		pos_x++;
		specialcase(vars, pos_x, pos_y);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->assets[6], pos_x * 32, pos_y * 32 + 32);
		vars->map.x_player = pos_x;
		ft_printf("Number of movement : %i\n", vars->nbhit);
	}
}
