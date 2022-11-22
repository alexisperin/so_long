/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legal_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:51:12 by aperin            #+#    #+#             */
/*   Updated: 2022/11/22 21:10:35 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	rectangular_map(t_game *game)
{
	int	y;

	y = 1;
	game->width = ft_strlen(game->map[0]);
	while (y < game->height)
	{
		if ((int) ft_strlen(game->map[y]) != game->width)
			return (0);
		y++;
	}
	return (1);
}

static int	only_one(t_game *game, char item)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == item)
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		return (0);
	return (1);
}

static int	at_least_one(t_game *game, char item)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == item)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	map_closed(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < game->height - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	legal_map(t_game *game)
{
	if (!rectangular_map(game))
		print_error("Map is not rectangular\n", 0);
	else if (contains_unknown_item(game))
		print_error("Map contains unknown items\n", 0);
	else if (!only_one(game, 'P'))
		print_error("Map does not have exactly one starting position\n", 0);
	else if (!only_one(game, 'E'))
		print_error("Map does not have exactly one exit\n", 0);
	else if (!at_least_one(game, 'C'))
		print_error("Map does not have at least one collectible\n", 0);
	else if (!map_closed(game))
		print_error("Map is not close/surrounded by walls\n", 0);
	// else if (!valid_path(game))
	// 	print_error("No valid path in map\n", 0);
	else
		return (1);
	return (0);
}
