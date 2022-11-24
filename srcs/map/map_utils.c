/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:49 by aperin            #+#    #+#             */
/*   Updated: 2022/11/24 11:01:18 by aperin           ###   ########.fr       */
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

void	set_legal_moves(char **map, t_pos player, t_moves *moves)
{
	moves->up = 0;
	moves->down = 0;
	moves->left = 0;
	moves->right = 0;
	if (map[player.y - 1][player.x] != '1')
		moves->up = 1;
	if (map[player.y + 1][player.x] != '1')
		moves->down = 1;
	if (map[player.y][player.x - 1] != '1')
		moves->left = 1;
	if (map[player.y][player.x + 1] != '1')
		moves->right = 1;
}

int	equal_pos(t_pos pos1, t_pos pos2)
{
	return (pos1.x == pos2.x && pos1.y == pos2.y);
}
