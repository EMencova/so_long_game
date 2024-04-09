/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:46:20 by emencova          #+#    #+#             */
/*   Updated: 2024/03/29 13:46:26 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	counter(t_list *my_game, int height, int width)
{
	if (my_game->map[height][width] != '1' &&
			my_game->map[height][width] != '0' &&
			my_game->map[height][width] != 'P' &&
			my_game->map[height][width] != 'E' &&
			my_game->map[height][width] != 'C' &&
			my_game->map[height][width] != '\n')
	{
		ft_printf("\n Error Here");
		exit(0);
	}
	if (my_game->map[height][width] == 'C')
		my_game->ccount++;
	if (my_game->map[height][width] == 'P')
		my_game->pcount++;
	if (my_game->map[height][width] == 'E')
		my_game->ecount++;
}

void	charact_check(t_list *my_game)
{
	int		height;
	int		width;

	height = 0;
	while (height < my_game->mheight -1)
	{
		width = 0;
		while (width <= my_game->mwidth)
		{
			counter(my_game, height, width);
			width++;
		}
		height++;
	}
	if (!(my_game->pcount == 1 && my_game->ccount > 1
			&& my_game->ecount == 1))
	{
		ft_printf("Error");
		exit (0);
	}
}

void	error_check(t_list *my_game)
{
	wall_check(my_game);
	charact_check(my_game);
}
