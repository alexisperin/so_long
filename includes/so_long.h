/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:08:41 by aperin            #+#    #+#             */
/*   Updated: 2022/11/24 09:07:51 by aperin           ###   ########.fr       */
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

typedef struct s_moves
{
	int	up;
	int	down;
	int	left;
	int	right;
}		t_moves;

typedef struct s_game
{
	char	**map;
	int		height;
	int		width;
	t_pos	player;
	t_moves	moves;
	int		food_left;
	int		nb_move;
}			t_game;

typedef struct s_path
{
	t_pos			pos;
	struct s_path	*next;
}					t_path;

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
int		legal_move(t_game *game, char move); // Not needed ???
void	set_legal_moves(t_game *game);
int		equal_pos(t_pos pos1, t_pos pos2);

#endif