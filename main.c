/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:30:55 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/18 18:06:12 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_vars *vars)
{
	int	i;

	i = 0;
	while(vars->map.map[i])
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
	while(vars->assets[i])
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

char	searchpos(t_vars *vars, size_t pos_x, size_t pos_y)
{
	size_t	x;
	size_t	y;

	y = 0;
	while(vars->map.map[y])
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
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[0], pos_x * 32, pos_y * 32 + 32);
		pos_y--;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[3], pos_x * 32, pos_y * 32 + 32);
		vars->map.y_player = pos_y;
		vars->nbhit++;
		ft_printf("Number of movement : %i\n",vars->nbhit);
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
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[0], pos_x * 32, pos_y * 32 + 32);
		pos_y++;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[4], pos_x * 32, pos_y * 32 + 32);
		vars->map.y_player = pos_y;
		vars->nbhit++;
		ft_printf("Number of movement : %i\n",vars->nbhit);
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
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[0], pos_x * 32, pos_y * 32 + 32);
		pos_x--;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[5], pos_x * 32, pos_y * 32 + 32);
		vars->map.x_player = pos_x;
		vars->nbhit++;
		ft_printf("Number of movement : %i\n",vars->nbhit);
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
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[0], pos_x * 32, pos_y * 32 + 32);
		pos_x++;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[6], pos_x * 32, pos_y * 32 + 32);
		vars->map.x_player = pos_x;
		vars->nbhit++;
		ft_printf("Number of movement : %i\n",vars->nbhit);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		close_window(vars);
	else if (keycode == XK_w)
		moveplayer_up(vars);
	else if (keycode == XK_s)
		moveplayer_down(vars);
	else if (keycode == XK_a)
		moveplayer_left(vars);
	else if (keycode == XK_d)
		moveplayer_right(vars);
	return(0);
}

void	set_assets(t_vars *vars)
{
	void	**assets;
	int		size;

	assets = malloc(sizeof(void *) * 11);
	if (!assets)
		return ;
	size = 32;
	assets[0] = mlx_xpm_file_to_image(vars->mlx, "assets/background.xpm", &size, &size);
	assets[1] = mlx_xpm_file_to_image(vars->mlx, "assets/wall1.xpm", &size, &size);
	assets[2] = mlx_xpm_file_to_image(vars->mlx, "assets/wall2.xpm", &size, &size);
	assets[3] = mlx_xpm_file_to_image(vars->mlx, "assets/player_up.xpm", &size, &size);
	assets[4] = mlx_xpm_file_to_image(vars->mlx, "assets/player_down.xpm", &size, &size);
	assets[5] = mlx_xpm_file_to_image(vars->mlx, "assets/player_left.xpm", &size, &size);
	assets[6] = mlx_xpm_file_to_image(vars->mlx, "assets/player_right.xpm", &size, &size);
	assets[7] = mlx_xpm_file_to_image(vars->mlx, "assets/end_on.xpm", &size, &size);
	assets[8] = mlx_xpm_file_to_image(vars->mlx, "assets/end_off.xpm", &size, &size);
	assets[9] = mlx_xpm_file_to_image(vars->mlx, "assets/collectible.xpm", &size, &size);
	assets[10] = NULL;
	vars->assets = assets;
}

int	main(int argc, char **argv)
{
	t_vars	vars;
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
	if (setmap(brutmap, &vars) == 0 || isvalid_map(&vars) == 0)
	{
		destroy_map(&vars);
		ft_printf("Error\nThe map isn't correct !");
		return (0);
	}
	vars.nbhit = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.map.size_x * 32), (vars.map.size_y * 32 + 32), "Star Citizen 1.0");
	set_assets(&vars);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 17, StructureNotifyMask, close_window, &vars);
	buildstart(&vars);
	mlx_loop(vars.mlx);
}
