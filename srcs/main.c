/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:08:54 by aperin            #+#    #+#             */
/*   Updated: 2022/12/01 14:17:17 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"\

int	main(int ac, char **av)
{
	t_game	*game;

	if (!check_input(ac, av))
		exit(EXIT_FAILURE);
	game = init_game(av[1]);
	if (!game)
		exit(EXIT_FAILURE);
	play_game(game);
	free_game(game);
	exit(EXIT_SUCCESS);
}
