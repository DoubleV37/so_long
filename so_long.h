/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:53:08 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/18 18:01:06 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include "fcntl.h"
# include "libft.h"

typedef struct s_map
{
	char	**map;
	size_t	size_x;
	size_t	size_y;
	size_t	nbcollec;
	size_t	x_player;
	size_t	y_player;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		nbhit;
	t_map	map;
	void	**assets;
}	t_vars;

char	*open_file(char	*path);
size_t	len_line_map_isvalid(char **map);
int	setmap(char *mapwithnl, t_vars *vars);
int	isvalid_map(t_vars *vars);
void	buildstart(t_vars *vars);

#endif
