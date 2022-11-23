/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:49 by aperin            #+#    #+#             */
/*   Updated: 2022/11/23 15:42:48 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	set_food_left(t_game *game)
{
	int	x;
	int	y;

	game->food_left = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
				(game->food_left)++;
			x++;
		}
		y++;
	}
}

int	legal_move(t_game *game, char move)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (move == 'u' && game->map[y - 1][x] == '1')
		return (0);
	else if (move == 'd' && game->map[y + 1][x] == '1')
		return (0);
	else if (move == 'l' && game->map[y][x - 1] == '1')
		return (0);
	else if (move == 'r' && game->map[y][x + 1] == '1')
		return (0);
	return (1);
}

char	*get_legal_moves(t_game *game)
{
	char	moves;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = game->player.x;
	y = game->player.y;
	if (game->map[y - 1][x] != '1')
		moves[i++] = 'u';
	if (game->map[y + 1][x] != '1')
		moves[i++] = 'd';
	if (game->map[y][x - 1] != '1')
		moves[i++] = 'l';
	if (game->map[y][x + 1] != '1')
		moves[i++] = 'r';
	moves[i] = 0;
	return(moves);
}
