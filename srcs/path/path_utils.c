/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:06:47 by aperin            #+#    #+#             */
/*   Updated: 2022/11/24 19:31:46 by aperin           ###   ########.fr       */
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

int	in_path(t_path *path, t_pos pos)
{
	while (path)
	{
		if (equal_pos(path->pos, pos))
			return (1);
		path = path->next;
	}
	return (0);
}

t_path	*free_path(t_path *path)
{
	t_path	*tmp;

	while (path)
	{
		tmp = path;
		path = path->next;
		free(tmp);
	}
	return (0);
}
