/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:12:59 by aperin            #+#    #+#             */
/*   Updated: 2022/11/24 11:18:34 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_path(t_game *game, t_pos player, t_pos dest)
{
	t_path	*allowed;
	t_path	*visited;
	t_moves	moves;

	if (equal_pos(player, dest))
		return (1);
	add_pos_to_path(visited, player);
	set_legal_moves(game->map, player, &moves);
	
}

int	check_path(t_game *game)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < game->height)
	{
		pos.x = 0;
		while (pos.x < game->width)
		{
			if (game->map[pos.y][pos.x] == 'E' && !valid_path(game, pos))
			{
				print_error("No valid path to exit\n", 0);
				return (0);
			}
			if (game->map[pos.y][pos.x] == 'C' && !valid_path(game, pos))
			{
				print_error("No valid path to collectibles\n", 0);
				return (0);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}