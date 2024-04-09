/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:53:47 by emencova          #+#    #+#             */
/*   Updated: 2024/03/28 12:54:02 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	*ft_memset(void *ptr, int value, size_t count)
{
	unsigned char	*strptr;
	size_t			i;

	strptr = (unsigned char *)ptr;
	i = 0;
	while (i < count)
	{
		strptr[i] = value;
		i++;
	}
	return (ptr);
}

int	main(int ac, char **av)
{
	t_list	my_game;

	if (ac != 2)
		return (0);
	ft_memset(&my_game, 0, sizeof(t_list));
	read_map(&my_game, av);
	error_check(&my_game);
	my_game.mlxptr = mlx_init();
	my_game.winptr = mlx_new_window(my_game.mlxptr, (my_game.mwidth * 40), \
		my_game.mheight * 40, "so_long");
	img_pos(&my_game);
	add_graph(&my_game);
	mlx_key_hook(my_game.winptr, controls, &my_game);
	mlx_hook(my_game.winptr, 17, 0, (void *)exit, 0);
	mlx_loop(my_game.mlxptr);
}
