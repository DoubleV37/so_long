/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_solong_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:17:05 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/24 14:01:53 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_map(t_vars *vars)
{
	int	i;

	i = 0;
	if (!vars->map.map)
		return ;
	while (vars->map.map[i])
	{
		free(vars->map.map[i]);
		i++;
	}
	free(vars->map.map);
}

void	destroy_assets(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->assets[i])
	{
		mlx_destroy_image(vars->mlx, vars->assets[i]);
		i++;
	}
	free(vars->assets);
	destroy_map(vars);
}

int	close_window(t_vars *vars)
{
	destroy_assets(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}
