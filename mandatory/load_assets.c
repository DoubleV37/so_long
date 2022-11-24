/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:57:43 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/24 11:14:58 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_wall(void **assets, t_vars *vars, int size)
{
	assets[1] = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall1.xpm", &size, &size);
	assets[2] = mlx_xpm_file_to_image
		(vars->mlx, "assets/wall2.xpm", &size, &size);
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

	assets = malloc(sizeof(void *) * 11);
	if (!assets)
		return ;
	size = 32;
	assets[0] = mlx_xpm_file_to_image
		(vars->mlx, "assets/background.xpm", &size, &size);
	assets[9] = mlx_xpm_file_to_image
		(vars->mlx, "assets/collectible.xpm", &size, &size);
	load_wall(assets, vars, size);
	load_player(assets, vars, size);
	load_end(assets, vars, size);
	assets[10] = NULL;
	vars->assets = assets;
}
