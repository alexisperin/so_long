/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_lst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:06:47 by aperin            #+#    #+#             */
/*   Updated: 2022/11/24 14:38:54 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_path	*add_to_path(t_path *path, t_pos pos)
{
	t_path	*new_node;

	new_node = malloc(sizeof(t_path));
	if (!new_node)
		return (free_path(path));
	new_node->pos.x = pos.x;
	new_node->pos.y = pos.y;
	new_node->next = path;
	return (new_node);
}

t_path	*add_moves_to_path(t_path *allowed, t_path *visited, char **map,
							t_pos curr_pos)
{
	t_pos	next_pos;
	int		moves[4];

	set_legal_moves(map, curr_pos, moves);
	if (move[0])
		
}
