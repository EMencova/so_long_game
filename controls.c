/* ************************************************************************** */
/*                                                          */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:07:14 by emencova          #+#    #+#             */
/*   Updated: 2024/03/28 11:21:08 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	move_right(t_list *my_game, int i, int j)
{
	int	value;

	if (my_game->map[j][i] == 'E')
	{
		if (my_game->collect != 0)
			return (0);
		else
		{
			write(1, "\nYou won!", 9);
			ptr_exit(my_game);
		}
	}
	else if (my_game->map[j][i] == '0' || my_game->map[j][i] == 'C')
	{
		value = 0;
		if (my_game->map[j][i] == 'C')
		{
			value = -1;
		}
		move_player(my_game, i, j, value);
	}
	return (1);
}

int	key_w(t_list *my_game, int move)
{
	int	i;
	int	j;

	i = my_game->x_axis;
	j = my_game->y_axis;
	if (move == 119)
	{
		j--;
		if (my_game->map[j][i] == '1' || !move_right(my_game, i, j))
			return (0);
		my_game->map[j + 1][i] = '0';
	}
	my_game->counter++;
	ft_printf("You have taken: %d steps\n", my_game->counter);
	ft_printf("You have: %d collectables remaining.\n", my_game->collect);
	return (1);
}

int	key_s(t_list *my_game, int move)
{
	int	i;
	int	j;

	i = my_game->x_axis;
	j = my_game->y_axis;
	if (move == 115)
	{
		j++;
		if (my_game->map[j][i] == '1' || !move_right(my_game, i, j))
			return (0);
		my_game->map[j - 1][i] = '0';
	}
	my_game->counter++;
	ft_printf("You have taken: %d steps\n", my_game->counter);
	ft_printf("You have: %d collectables remaining.\n", my_game->collect);
	return (1);
}

int	key_a(t_list *my_game, int move)
{
	int	i;
	int	j;

	i = my_game->x_axis;
	j = my_game->y_axis;
	if (move == 97)
	{
		i--;
		if (my_game->map[j][i] == '1' || !move_right(my_game, i, j))
			return (0);
		my_game->map[j][i + 1] = '0';
	}
	my_game->counter++;
	ft_printf("You have taken: %d steps\n", my_game->counter);
	ft_printf("You have: %d collectables remaining.\n", my_game->collect);
	return (1);
}

int	key_d(t_list *my_game, int move)
{
	int	i;
	int	j;

	i = my_game->x_axis;
	j = my_game->y_axis;
	if (move == 100)
	{
		i++;
		if (my_game->map[j][i] == '1' || !move_right(my_game, i, j))
			return (0);
		my_game->map[j][i - 1] = '0';
	}
	my_game->counter++;
	ft_printf("You have taken: %d steps\n", my_game->counter);
	ft_printf("You have: %d collectables remaining.\n", my_game->collect);
	return (1);
}
