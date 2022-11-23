/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:57:28 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/23 16:52:44 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isber(char	*path)
{
	size_t	i;

	i = ft_strlen(path) - 1;
	if (path[i] == 'r' && path[i - 1] == 'e'
		&& path[i - 2] == 'b' && ft_isprint(path[i - 3]))
		return (1);
	return (0);
}

char	*open_file(char	*path)
{
	int		fd;
	char	*str;
	char	*line;

	if (!isber(path))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
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
	return (str);
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
	while (vars->map.map[i])
		i++;
	vars->map.size_y = i;
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
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->assets[0], x * 32, y * 32 + 32);
			else if (vars->map.map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->assets[8], x * 32, y * 32 + 32);
			else if (vars->map.map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->assets[3], x * 32, y * 32 + 32);
			else if (vars->map.map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->assets[9], x * 32, y * 32 + 32);
			else
			{
				if (x % 2 == 0)
					mlx_put_image_to_window(vars->mlx, vars->win,
						vars->assets[1], x * 32, y * 32 + 32);
				else
					mlx_put_image_to_window(vars->mlx, vars->win,
						vars->assets[2], x * 32, y * 32 + 32);
			}
			x++;
		}
		y++;
	}
}
