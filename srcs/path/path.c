/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:12:59 by aperin            #+#    #+#             */
/*   Updated: 2022/11/27 13:17:22 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_path *bfs_algo(char **map, t_path *allowed, t_path *visited)
{
	int		moves[4];
	int		i;
	t_vector	curr_pos;
	t_vector	new_pos;

	curr_pos = allowed->pos;
	allowed = push_path(allowed, visited);
	get_legal_moves(map, curr_pos, moves);
	i = 0;
	while (i < 4)
	{
		if (moves[i])
		{
			new_pos = make_move(curr_pos, i);
			if (!in_path(visited, new_pos))
			{
				allowed = add_to_path(allowed, new_pos);
				if (!allowed)
					return (free_path(visited));
			}
		}
		i++;
	}
	return (allowed);
}

static int	valid_path(t_game *game, t_vector dest)
{
	t_path	*allowed;
	t_path	*visited;

	allowed = add_to_path(0, game->player);
	if (!allowed)
		return (0);
	visited = add_to_path(0, game->player);
	if (!visited)
	{
		free_path(visited);
		return (0);
	}
	while (allowed)
	{
		if (equal_pos(allowed->pos, dest))
		{
			free_path(allowed);
			free_path(visited);
			return (1);
		}
		allowed = bfs_algo(game->map, allowed, visited);
	}
	free_path(visited);
	return (0);
}

int	check_path(t_game *game)
{
	t_vector	pos;

	pos.y = 0;
	while (pos.y < game->size.y)
	{
		pos.x = 0;
		while (pos.x < game->size.x)
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
