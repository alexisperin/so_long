/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:08:54 by aperin            #+#    #+#             */
/*   Updated: 2022/11/22 18:50:10 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void print_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (!check_input(ac, av))
		exit(EXIT_FAILURE);
	game = init_game(av[1]);
	if (!game)
		exit(EXIT_FAILURE);
	print_map(game);
	exit(EXIT_SUCCESS);
}
