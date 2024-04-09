/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:31:17 by emencova          #+#    #+#             */
/*   Updated: 2024/03/28 11:48:32 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_list
{
	int		fd;
	int		mheight;
	int		mwidth;
	int		pcount;
	int		ccount;
	int		ecount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collect;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxptr;
	void	*winptr;
}		t_list;

int			move_right(t_list *my_game, int i, int j);
int			ft_printf(const char *format, ...);
int			read_map(t_list *my_game, char **av);
int			controls(int command, t_list *my_game);
int			ptr_exit(t_list *my_game);
int			controls(int command, t_list *my_game);
int			key_w(t_list *my_game, int move);
int			key_s(t_list *my_game, int move);
int			key_a(t_list *my_game, int move);
int			key_d(t_list *my_game, int move);
void		error_check(t_list *my_game);
void		img_pos(t_list *my_game);
void		add_graph(t_list *my_game);
void		wall_check(t_list *my_game);
void		charact_check(t_list *my_game);
void		render_game(t_list *game);
void		draw_map(t_list *game);
void		draw_player(t_list *my_game);
void		draw_collectibles(t_list *my_game, int height, int width);
void		img_pos(t_list *my_game);
void		collect_pos(t_list *my_game, int height, int width);
void		move_player(t_list *my_game, int i, int j, int collect_increment);
void		player_pos(t_list *my_game, int height, int width);

#endif
