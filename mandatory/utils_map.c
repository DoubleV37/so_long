/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:57:28 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/02 10:57:30 by vviovi           ###   ########.fr       */
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

void	ctrl_end(t_vars *vars)
{
	if (vars->map.x_end == vars->map.x_player
		&& vars->map.y_end == vars->map.y_player)
	{
		if (vars->map.nbcollec == vars->nbcollget)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[7],
				vars->map.x_end * 32, vars->map.y_end * 32);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->assets[8],
				vars->map.x_end * 32, vars->map.y_end * 32);
	}
}

int	cpt_contentmap(t_vars *vars, int *nbstart, int *nbend, size_t *y)
{
	size_t	x;

	x = 0;
	while (vars->map.map[*y][x])
	{
		if (is_invalid_contentmap(vars, x, y))
			return (0);
		else if (vars->map.map[*y][x] == 'E')
		{
			vars->map.x_end = x;
			vars->map.y_end = (*y);
			(*nbend)++;
		}
		else if (vars->map.map[*y][x] == 'C')
			vars->map.nbcollec++;
		else if (vars->map.map[*y][x] == 'P')
		{
			vars->map.x_player = x;
			vars->map.y_player = (*y);
			(*nbstart)++;
		}
		x++;
	}
	return (1);
}
