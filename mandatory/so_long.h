/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:53:08 by vviovi            #+#    #+#             */
/*   Updated: 2022/11/24 13:28:32 by vviovi           ###   ########.fr       */
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
	int		nbcollec;
	size_t	x_player;
	size_t	y_player;
	size_t	x_end;
	size_t	y_end;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		nbhit;
	int		nbcollget;
	t_map	map;
	void	**assets;
}	t_vars;

char	*open_file(char	*path);
int		setmap(char *mapwithnl, t_vars *vars);
int		isber(char	*path);
void	ctrl_end(t_vars *vars);
int		cpt_contentmap(t_vars *vars, int *nbstart, int *nbend, size_t *y);

int		isvalid_map(t_vars *vars);
void	duplmap(t_map *dest, t_map *src);
int		is_fill(t_map *map);
int		verif_fillmap(t_map *map, size_t x, size_t y);
size_t	len_line_map_isvalid(char **map);

int		is_solvable(t_map *map);

void	destroy_map(t_vars *vars);
void	destroy_assets(t_vars *vars);
void	free_map(char ***map);
int		close_window(t_vars *vars);

void	specialcase(t_vars *vars, size_t next_x, size_t next_y);
void	moveplayer_up(t_vars *vars);
void	moveplayer_down(t_vars *vars);
void	moveplayer_left(t_vars *vars);
void	moveplayer_right(t_vars *vars);

char	searchpos(t_vars *vars, size_t pos_x, size_t pos_y);

void	set_assets(t_vars *vars);
void	load_end(void **assets, t_vars *vars, int size);
void	load_player(void **assets, t_vars *vars, int size);
void	load_wall(void **assets, t_vars *vars, int size);

void	endgame(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	buildstart(t_vars *vars);
void	init_vars_and_win(t_vars *vars);
void	put_image_win(t_vars *vars, size_t x, size_t y);

void	modifmap(t_vars *vars, size_t pos_x, size_t pos_y, char typeimg);

#endif
