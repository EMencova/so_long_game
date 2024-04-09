/* ************************************************************************** */
/*                                                                        */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emencova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:35:50 by emencova          #+#    #+#             */
/*   Updated: 2024/03/29 14:35:54 by emencova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static int	map_width(char *str)
{
	int	width;

	width = 0;
	while (str[width] != '\0')
		width++;
	if (str[width - 1] == '\n')
		width--;
	return (width);
}

static int	more_lines(t_list *my_game, char *line)
{
	char	**temp;
	int		i;

	if (line == 0)
		return (0);
	i = 0;
	my_game->mheight++;
	temp = (char **)malloc(sizeof(char *) * (my_game->mheight + 1));
	temp[my_game->mheight] = NULL;
	while (i < my_game->mheight -1)
	{
		temp[i] = my_game->map[i];
		i++;
	}
	temp[i] = line;
	if (my_game->map)
		free(my_game->map);
	my_game->map = temp;
	return (1);
}

int	read_map(t_list *my_game, char **av)
{
	char	*read;

	my_game->fd = open(av[1], O_RDONLY);
	if (my_game->fd < 0)
		return (0);
	while (1)
	{
		read = get_next_line(my_game->fd);
		if (!more_lines(my_game, read))
			break ;
	}
	close(my_game->fd);
	my_game->mwidth = map_width(my_game->map[0]);
	return (1);
}

int	ptr_exit(t_list *my_game)
{
	int	l;

	l = 0;
	if (my_game->winptr)
		mlx_destroy_window(my_game->mlxptr, my_game->winptr);
	while (l < my_game->mheight)
		free(my_game->map[l++]);
	if (my_game->exit)
		mlx_destroy_image(my_game->mlxptr, my_game->exit);
	if (my_game->collectable)
		mlx_destroy_image(my_game->mlxptr, my_game->collectable);
	if (my_game->player)
		mlx_destroy_image(my_game->mlxptr, my_game->player);
	if (my_game->floor)
		mlx_destroy_image(my_game->mlxptr, my_game->floor);
	if (my_game->barrier)
		mlx_destroy_image(my_game->mlxptr, my_game->barrier);
	mlx_destroy_display(my_game->mlxptr);
	free(my_game->mlxptr);
	free(my_game->map);
	exit (0);
}
