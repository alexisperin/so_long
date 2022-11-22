/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:08:41 by aperin            #+#    #+#             */
/*   Updated: 2022/11/22 15:49:17 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

# include <stdio.h> // TO REMOVE !!!

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_game
{
	char	**map;
	int		height;
	int		width;
	t_pos	*player_pos;
	int		food_left;
	int		nb_move;
}			t_game;


// Error
int		print_error(char *str, int call_perror);

// Input
int		check_input(int ac, char **av);

// Game
t_game	*init_game(char *file_name);




#endif