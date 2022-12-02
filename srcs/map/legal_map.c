/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legal_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:51:12 by aperin            #+#    #+#             */
/*   Updated: 2022/12/02 13:46:40 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	rectangular_map(t_game *game)
{
	int	y;

	y = 1;
	if (!game->map || !game->map[0])
		return (0);
	game->size.x = ft_strlen(game->map[0]);
	while (y < game->size.y)
	{
		if ((int) ft_strlen(game->map[y]) != game->size.x)
			return (0);
		y++;
	}
	return (1);
}

static int	unknown_items(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0'
				&& game->map[y][x] != 'P' && game->map[y][x] != 'E'
				&& game->map[y][x] != 'C' && game->map[y][x] != 'G')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	nb_items(t_game *game, char item)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->map[y][x] == item)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static int	map_closed(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size.x)
	{
		if (game->map[0][i] != '1' || game->map[game->size.y - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < game->size.y - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][game->size.x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	legal_map(t_game *game)
{
	if (!rectangular_map(game))
		return (print_error("Map is not rectangular\n", 0));
	else if (unknown_items(game))
		return (print_error("Map contains unknown items\n", 0));
	else if (nb_items(game, 'P') != 1)
		return (print_error("Map does not have exactly one starting position\n",
				0));
	else if (nb_items(game, 'E') != 1)
		return (print_error("Map does not have exactly one exit\n", 0));
	else if (nb_items(game, 'C') < 1)
		return (print_error("Map does not have at least one collectible\n", 0));
	else if (!map_closed(game))
		return (print_error("Map is not close/surrounded by walls\n", 0));
	set_player(game);
	set_food_left(game);
	if (!check_path(game))
		return (0);
	else
		return (1);
}
