/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:41:43 by aperin            #+#    #+#             */
/*   Updated: 2022/11/23 09:03:38 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "so_long.h"
#include "get_next_line.h"
#include "libft.h"

t_game	*free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
	return (0);
}

static void	init_map(int fd, t_game *game)
{
	char	*line;
	char	*buf;
	char	*tmp;

	game->height = 0;
	buf = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = buf;
		buf = ft_strjoin(buf, line);
		free(tmp);
		(game->height)++;
	}
	game->map = ft_split(buf, '\n');
	free(buf);
}

t_game	*init_game(char *file_name)
{
	t_game	*game;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		print_error(0, 1);
		return (0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	init_map(fd, game);
	if (!legal_map(game))
		return (free_game(game));
	game->nb_move = 0;
	close(fd);
	return (game);
}
