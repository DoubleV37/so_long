/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:30:55 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/24 14:02:07 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	modifmap(t_vars *vars, size_t pos_x, size_t pos_y, char typeimg)
{
	vars->map.map[pos_y][pos_x] = typeimg;
}

int	error_traitment(int argc, char **argv, t_vars *vars)
{
	char	*brutmap;

	if (argc != 2)
	{
		ft_printf("Error\nMissing map in argv !");
		return (0);
	}
	brutmap = open_file(argv[1]);
	if (brutmap == NULL)
	{
		ft_printf("Error\nCan't open the map !");
		return (0);
	}
	if (setmap(brutmap, vars) == 0 || isvalid_map(vars) == 0)
	{
		destroy_map(vars);
		ft_printf("Error\nThe map isn't correct !");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (!error_traitment(argc, argv, &vars))
		exit (0);
	init_vars_and_win(&vars);
	buildstart(&vars);
	mlx_loop(vars.mlx);
}
