/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:49 by aperin            #+#    #+#             */
/*   Updated: 2022/12/02 09:42:13 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(t_game *game)
{
	int	x;
	int	y;

	game->enemy.x = 0;
	game->enemy.y = 0;
	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
			}
			if (game->map[y][x] == 'G')
			{
				game->enemy.x = x;
				game->enemy.y = y;
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
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->map[y][x] == 'C')
				(game->food_left)++;
			x++;
		}
		y++;
	}
}

void	get_legal_moves(char **map, t_vector player, int moves[4])
{
	moves[0] = 0;
	moves[1] = 0;
	moves[2] = 0;
	moves[3] = 0;
	if (map[player.y - 1][player.x] != '1')
		moves[0] = 1;
	if (map[player.y + 1][player.x] != '1')
		moves[1] = 1;
	if (map[player.y][player.x - 1] != '1')
		moves[2] = 1;
	if (map[player.y][player.x + 1] != '1')
		moves[3] = 1;
}

int	equal_pos(t_vector pos1, t_vector pos2)
{
	return (pos1.x == pos2.x && pos1.y == pos2.y);
}

t_vector	make_move(t_vector curr_pos, int move)
{
	t_vector	new_pos;

	new_pos = curr_pos;
	if (move == 0)
		new_pos.y -= 1;
	else if (move == 1)
		new_pos.y += 1;
	else if (move == 2)
		new_pos.x -= 1;
	else if (move == 3)
		new_pos.x += 1;
	return (new_pos);
}
