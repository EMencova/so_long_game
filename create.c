/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:36:08 by emencova          #+#    #+#             */
/*   Updated: 2024/04/04 12:36:10 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	render_static_elements(t_list *my_game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < my_game->mheight)
	{
		x = 0;
		while (x < my_game->mwidth)
		{
			if (my_game->map[y][x] == '1')
				mlx_put_image_to_window(my_game->mlxptr, my_game->winptr,
					my_game->barrier, x * 40, y * 40);
			else if (my_game->map[y][x] == 'E')
				mlx_put_image_to_window(my_game->mlxptr, my_game->winptr,
					my_game->exit, x * 40, y * 40);
			else
				mlx_put_image_to_window(my_game->mlxptr, my_game->winptr,
					my_game->floor, x * 40, y * 40);
			x++;
		}
		y++;
	}
}

void	render_dynamic_elements(t_list *my_game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < my_game->mheight)
	{
		x = 0;
		while (x < my_game->mwidth)
		{
			if (my_game->map[y][x] == 'P')
				mlx_put_image_to_window(my_game->mlxptr, my_game->winptr,
					my_game->player, x * 40, y * 40);
			else if (my_game->map[y][x] == 'C')
				mlx_put_image_to_window(my_game->mlxptr, my_game->winptr,
					my_game->collectable, x * 40, y * 40);
			x++;
		}
		y++;
	}
}

void	render_game(t_list *my_game)
{
	render_static_elements(my_game);
	render_dynamic_elements(my_game);
}
