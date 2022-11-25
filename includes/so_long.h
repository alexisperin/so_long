/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:08:41 by aperin            #+#    #+#             */
/*   Updated: 2022/11/25 09:46:56 by aperin           ###   ########.fr       */
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
	int		score;
}			t_game;

typedef struct s_path
{
	t_pos			pos;
	struct s_path	*next;
}					t_path;

void print_path(t_path *path); // TO REMOVE !!!

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
void	get_legal_moves(char **map, t_pos player, int moves[4]);
int		equal_pos(t_pos pos1, t_pos pos2);
t_pos	make_move(t_pos curr_pos, int move);

// Path utils
t_path	*add_to_path(t_path *path, t_pos pos);
int		in_path(t_path *path, t_pos pos);
t_path	*push_path(t_path *allowed, t_path *visited);
t_path	*free_path(t_path *path);

#endif