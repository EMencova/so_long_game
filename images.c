/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:57:15 by emencova          #+#    #+#             */
/*   Updated: 2024/03/29 13:57:19 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	player_pos(t_list *my_game, int height, int width)
{
	mlx_put_image_to_window(my_game->mlxptr, my_game->winptr, \
		my_game->player, width * 40, height * 40);
	my_game->y_axis = height;
	my_game->x_axis = width;
}

void	collect_pos(t_list *my_game, int height, int width)
{
	mlx_put_image_to_window(my_game->mlxptr, my_game->winptr, \
		my_game->collectable, width * 40, height * 40);
	my_game->collect++;
}

void	add_static_elements(t_list *my_game)
{
	int	height;
	int	width;

	height = 0;
	while (height < my_game->mheight)
	{
		width = 0;
		while (my_game->map[height][width])
		{
			if (my_game->map[height][width] == '1')
				mlx_put_image_to_window(my_game->mlxptr, my_game->winptr,
					my_game->barrier, width * 40, height * 40);
			else if (my_game->map[height][width] == 'E')
				mlx_put_image_to_window(my_game->mlxptr, my_game->winptr,
					my_game->exit, width * 40, height * 40);
			else if (my_game->map[height][width] == '0')
				mlx_put_image_to_window(my_game->mlxptr, my_game->winptr,
					my_game->floor, width * 40, height * 40);
			width++;
		}
		height++;
	}
}

void	add_dynamic_elements(t_list *my_game)
{
	int	height;
	int	width;

	height = 0;
	while (height < my_game->mheight)
	{
		width = 0;
		while (my_game->map[height][width])
		{
			if (my_game->map[height][width] == 'C')
				collect_pos(my_game, height, width);
			else if (my_game->map[height][width] == 'P')
				player_pos(my_game, height, width);
			width++;
		}
		height++;
	}
}

void	add_graph(t_list *my_game)
{
	my_game->collect = 0;
	add_static_elements(my_game);
	add_dynamic_elements(my_game);
}
