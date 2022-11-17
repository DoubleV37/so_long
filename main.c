/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:30:55 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/17 18:01:44 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"
#include "fcntl.h"
#include "libft.h"

typedef struct s_map
{
	char	**map;
	size_t	size_x;
	size_t	size_y;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	map;
	void	**assets;
}	t_vars;

char	*open_file(char	*path)
{
	int		fd;
	char	*str;
	char	*line;

	//verifier que c'est bien un .ber
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return(NULL);
	str = malloc(sizeof(char));
	str[0] = '\0';
	line = get_next_line(fd);
	while (line)
	{
		str = ft_strjoin_free_first_param(str, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return(str);
}

size_t	len_line_map_isvalid(char **map)
{
	size_t	i;
	size_t	lenline;

	if (!map[0])
		return (0);
	i = 1;
	lenline = ft_strlen(map[0]);
	while(map[i])
	{
		if (ft_strlen(map[i]) != lenline)
			return (0);
		i++;
	}
	return (lenline);
}

int	setmap(char *mapwithnl, t_vars *vars)
{
	char	**map;
	size_t	i;
	size_t	lenline;

	i = 0;
	map = ft_split(mapwithnl, '\n');
	free(mapwithnl);
	lenline = len_line_map_isvalid(map);
	if (lenline == 0)
		return (0);
	vars->map.map = map;
	vars->map.size_x = lenline;
	while(vars->map.map[i])
		i++;
	vars->map.size_y = i;
	return (1);
}

int	isvalid_map(t_vars *vars)
{
	if(vars->map.map)
		return(1);
	return (0);
}

void	*create_img(char *path, int width, int height, void *mlx)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	return(img);
}

#include <stdio.h>

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
			if (vars->map.map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[0], x * 32, y * 32);
			else if (vars->map.map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[8], x * 32, y * 32);
			else if (vars->map.map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[3], x * 32, y * 32);
			else if (vars->map.map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[9], x * 32, y * 32);
			else
			{
				if (x % 2 == 0)
					mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[1], x * 32, y * 32);
				else
					mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[2], x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

/*
int	isvalid_map(fd)
{
	char	*line_map;
	int		isvalid;
	int		nbstart;
	int		nbend;
	int		nbcollect;
	int		i;
	int		j;

	line_map = get_next_line(fd);
	i = 0;
	isvalid = 1;
	nbstart = 0;
	nbend = 0;
	nbcollect = 0;
	while (line_map)
	{
		j = 0;
		while (line_map[j])
		{
			if (i == 0 && line_map[j] != '1') //si c pas un mur => il faut rajouter pr la last ligne et les extremites
				isvalid = 0;
			else if (line_map[j] == 'C')
				nbcollect++;
			else if (line_map[j] == 'P')
				nbstart++;
			else if (line_map[j] == 'E')
				nbend++;
			j++;
		}
		free(line_map);
		line_map = get_next_line(fd);
		i++;
	}
	if (nbcollect < 1 || nbstart != 1 || nbend != 1)
		isvalid = 0;
	return(isvalid);
}*/

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		close_window(vars);
	return(0);
}

void	set_assets(t_vars *vars)
{
	void	**assets;

	assets = malloc(sizeof(void *) * 11);
	if (!assets)
		return ;
	assets[0] = create_img("assets/background.xpm", 32, 32, vars->mlx);
	assets[1] = create_img("assets/wall1.xpm", 32, 32, vars->mlx);
	assets[2] = create_img("assets/wall2.xpm", 32, 32, vars->mlx);
	assets[3] = create_img("assets/player_up.xpm", 32, 32, vars->mlx);
	assets[4] = create_img("assets/player_down.xpm", 32, 32, vars->mlx);
	assets[5] = create_img("assets/player_left.xpm", 32, 32, vars->mlx);
	assets[6] = create_img("assets/player_right.xpm", 32, 32, vars->mlx);
	assets[7] = create_img("assets/end_on.xpm", 32, 32, vars->mlx);
	assets[8] = create_img("assets/end_off.xpm", 32, 32, vars->mlx);
	assets[9] = create_img("assets/collectible.xpm", 32, 32, vars->mlx);
	assets[10] = NULL;
	vars->assets = assets;
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	char	*brutmap;
	/*void	*back;
	void	*wall;
	void	*collect;*/

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
		ft_printf("Error\nThe map isn't correct !");
		return (0);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "HELLO WORLD !");
	set_assets(&vars);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 17, StructureNotifyMask, close_window, &vars);
	buildstart(&vars);
	/*back = create_img("assets/background.xpm", 32, 32, vars.mlx);
	wall = create_img("assets/wall1.xpm", 32, 32, vars.mlx);
	collect = create_img("assets/player_up.xpm", 32, 32, vars.mlx);
	mlx_put_image_to_window(vars.mlx, vars.win, back, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, back, 32, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, wall, 64, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, collect, 96, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, back, 128, 0);*/
	mlx_loop(vars.mlx);
}
