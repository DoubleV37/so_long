/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:57:43 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/28 17:17:11 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_wall(void **assets, t_vars *vars, int size)
{
	assets[1] = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall1.xpm", &size, &size);
	assets[2] = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall2.xpm", &size, &size);
	assets[10] = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall3-1.xpm", &size, &size);
	assets[11] = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall3-2.xpm", &size, &size);
	assets[12] = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall3-3.xpm", &size, &size);
	assets[13] = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall3-4.xpm", &size, &size);
	assets[14] = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall3-5.xpm", &size, &size);
	assets[15] = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall3-6.xpm", &size, &size);
	assets[16] = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall3-7.xpm", &size, &size);
	assets[17] = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall3-8.xpm", &size, &size);
	vars->nbwalltyp = 10;
}

void	load_player(void **assets, t_vars *vars, int size)
{
	assets[3] = mlx_xpm_file_to_image
		(vars->mlx, "assets/player_up.xpm", &size, &size);
	assets[4] = mlx_xpm_file_to_image
		(vars->mlx, "assets/player_down.xpm", &size, &size);
	assets[5] = mlx_xpm_file_to_image
		(vars->mlx, "assets/player_left.xpm", &size, &size);
	assets[6] = mlx_xpm_file_to_image
		(vars->mlx, "assets/player_right.xpm", &size, &size);
}

void	load_end(void **assets, t_vars *vars, int size)
{
	assets[7] = mlx_xpm_file_to_image
		(vars->mlx, "assets/end_on.xpm", &size, &size);
	assets[8] = mlx_xpm_file_to_image
		(vars->mlx, "assets/end_off.xpm", &size, &size);
}

void	set_assets(t_vars *vars)
{
	void	**assets;
	int		size;

	assets = malloc(sizeof(void *) * 20);
	if (!assets)
		return ;
	size = 32;
	assets[0] = mlx_xpm_file_to_image
		(vars->mlx, "assets/background.xpm", &size, &size);
	assets[9] = mlx_xpm_file_to_image
		(vars->mlx, "assets/collectible.xpm", &size, &size);
	assets[18] = mlx_xpm_file_to_image
		(vars->mlx, "assets/ennemi.xpm", &size, &size);
	load_wall(assets, vars, size);
	load_player(assets, vars, size);
	load_end(assets, vars, size);
	assets[19] = NULL;
	vars->assets = assets;
	vars->nbturn = 0;
}
