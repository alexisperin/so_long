/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:12:59 by aperin            #+#    #+#             */
/*   Updated: 2022/11/24 19:57:52 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_path	*push_path(t_path *allowed, t_path *visited)
{
	t_path	*tmp;

	if (!visited)
	{
		visited = allowed;
		allowed = allowed->next;
		visited->next = 0;
		return (allowed);
	}
	tmp = visited;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = allowed;
	allowed = allowed->next;
	return (allowed);
}

static t_path *dfs_algo(char **map, t_path *allowed, t_path *visited)
{
	int		moves[4];
	int		i;
	t_pos	new_pos;

	set_legal_moves(map, allowed->pos, moves);
	i = 0;
	while (i < 4)
	{
		if (moves[i])
		{
			new_pos = make_move(allowed->pos, i);
			allowed = push_path(allowed, visited);
			if (!in_path(visited, new_pos))
			{
				allowed = add_to_path(allowed, new_pos);
				if (!allowed)
					return (free_path(visited));
			}
		}
		i++;
	}
	printf("!!!!!!!!!!!!!\n");
	exit (1);
	return (allowed);
}

static int	valid_path(t_game *game, t_pos dest)
{
	t_path	*allowed;
	t_path	*visited;

	allowed = 0;
	visited = 0;
	allowed = add_to_path(allowed, game->player);
	if (!allowed)
		return (0);
	while (allowed)
	{
		if (equal_pos(allowed->pos, dest))
		{
			free_path(allowed);
			free_path(visited);
			return (1);
		}
		allowed = dfs_algo(game->map, allowed, visited);
	}
	free_path(visited);
	return (0);
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
