/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:57:28 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/21 16:20:07 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	while (map[i])
	{
		if (ft_strlen(map[i]) != lenline)
			return (0);
		i++;
	}
	return (lenline);
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

int	setmap(char *mapwithnl, t_vars *vars)
{
	char	**map;
	size_t	i;
	size_t	lenline;

	i = 0;
	vars->map.map = NULL;
	map = ft_split(mapwithnl, '\n');
	free(mapwithnl);
	lenline = len_line_map_isvalid(map);
	if (lenline == 0)
	{
		free_map(&map);
		return (0);
	}
	vars->map.map = map;
	vars->map.size_x = lenline;
	while(vars->map.map[i])
		i++;
	vars->map.size_y = i;
	return (1);
}

int	isvalid_map(t_vars *vars)
{
	size_t	nbstart;
	size_t	nbend;
	size_t	nbcollect;
	size_t	x;
	size_t	y;

	nbstart = 0;
	nbend = 0;
	nbcollect = 0;
	y = 0;
	while(vars->map.map[y])
	{
		x = 0;
		while(vars->map.map[y][x])
		{
			if ((y == 0 || y == vars->map.size_y - 1 || x == 0 || x == vars->map.size_x) && vars->map.map[y][x] != '1')
				return(0);
			else if (vars->map.map[y][x] == 'E')
			{
				vars->map.x_end = x;
				vars->map.y_end = y;
				nbend++;
			}
			else if (vars->map.map[y][x] == 'C')
				nbcollect++;
			else if (vars->map.map[y][x] == 'P')
			{
				vars->map.x_player = x;
				vars->map.y_player = y;
				nbstart++;
			}
			x++;
		}
		y++;
	}
	if(nbstart != 1 || nbend != 1 || nbcollect == 0) //verifier aussi si la map est solvable
		return(0);
	vars->map.nbcollec = nbcollect;
	return (1);
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
			if (vars->map.map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[0], x * 32, y * 32 + 32);
			else if (vars->map.map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[8], x * 32, y * 32 + 32);
			else if (vars->map.map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[3], x * 32, y * 32 + 32);
			else if (vars->map.map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[9], x * 32, y * 32 + 32);
			else
			{
				if (x % 2 == 0)
					mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[1], x * 32, y * 32 + 32);
				else
					mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[2], x * 32, y * 32 + 32);
			}
			x++;
		}
		y++;
	}
}
