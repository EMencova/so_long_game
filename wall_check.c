/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:41:12 by emencova          #+#    #+#             */
/*   Updated: 2024/03/29 14:41:14 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static int	horiz_wall( t_list *my_game)
{
	int	i;
	int	j;

	i = my_game->mwidth;
	j = 0;
	while (j < i)
	{
		if (my_game->map[0][i] == '1'
			&& my_game->map[my_game->mheight -1][j] == '1')
			return (0);
		j++;
	}
	return (1);
}

static int	vert_wall(t_list *my_game)
{
	int	height;
	int	width;

	height = 0;
	width = my_game->mwidth;
	if (width <= 1 || height >= my_game->mheight)
		return (0);
	while (height < my_game->mheight)
	{
		if (height >= 0 && height < my_game->mheight)
		{
			if (!(my_game->map[height][0] == '1'
				&& my_game->map[height][width - 1] == '1'))
				return (0);
		}
		else
			return (0);
		height++;
	}
	return (1);
}

void	wall_check(t_list *my_game)
{
	int	ver_walls;
	int	hor_walls;

	ver_walls = vert_wall(my_game);
	hor_walls = horiz_wall(my_game);
	if (!ver_walls || !hor_walls)
	{
		write(1, "Missing walls", 13);
		exit(0);
	}
}
