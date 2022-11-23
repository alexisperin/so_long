/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:08:41 by aperin            #+#    #+#             */
/*   Updated: 2022/11/23 16:15:04 by aperin           ###   ########.fr       */
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
	t_pos	player;
	int		food_left;
	int		nb_move;
	char	
}			t_game;


// Error
int		print_error(char *str, int call_perror);

// Input
int		check_input(int ac, char **av);

// Map
t_game	*init_game(char *file_name);
t_game	*free_game(t_game *game);
int		legal_map(t_game *game);
int		check_path(t_game *game);

// Map utils
void	set_player(t_game *game);
void	set_food_left(t_game *game);
int		legal_move(t_game *game, char move);
char	*get_legal_moves(t_game *game);

#endif