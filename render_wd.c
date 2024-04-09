/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:48:00 by emencova          #+#    #+#             */
/*   Updated: 2024/03/29 18:48:02 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	img_pos(t_list *my_game)
{
	int		i;
	int		j;

	my_game->floor = mlx_xpm_file_to_image(my_game->mlxptr, \
		"img/seafloor.xpm", &i, &j);
	my_game->barrier = mlx_xpm_file_to_image(my_game->mlxptr, \
		"img/land.xpm", &i, &j);
	my_game->player = mlx_xpm_file_to_image(my_game->mlxptr, \
		"img/Shark.xpm", &i, &j);
	my_game->exit = mlx_xpm_file_to_image(my_game->mlxptr, \
		"img/exit.xpm", &i, &j);
	my_game->collectable = mlx_xpm_file_to_image(my_game->mlxptr, \
		"img/squid.xpm", &i, &j);
}

void	move_player(t_list *my_game, int i, int j, int collect_increment)
{
	my_game->map[j][i] = 'P';
	if (i - 1 >= 0 && my_game->map[j][i - 1] != '1'
		&& (!move_right(my_game, i, j)))
	{
		my_game->map[j][i - 1] = '0';
		my_game->x_axis = i - 1;
		my_game->y_axis = j;
		my_game->collect += collect_increment;
	}
}

int	controls(int command, t_list *my_game)
{
	if (command == 65307)
		ptr_exit(my_game);
	if (command == 119)
	{
		key_w(my_game, command);
		add_graph(my_game);
	}
	if (command == 115)
	{
		key_s(my_game, command);
		add_graph(my_game);
	}
	if (command == 97)
	{
		key_a(my_game, command);
		add_graph(my_game);
	}
	if (command == 100)
	{
		key_d(my_game, command);
		add_graph(my_game);
	}
	return (1);
}
