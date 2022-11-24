/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_lst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:06:47 by aperin            #+#    #+#             */
/*   Updated: 2022/11/24 09:05:04 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_path	*add_pos_to_path(t_path *path, t_pos pos)
{
	t_path	*new_node;

	new_node = malloc(sizeof(t_path));
	if (!new_node)
		return (0);
	new_node.pos.x = pos.x;
	new_node.pos.y = pos.y;
	new_node
}
