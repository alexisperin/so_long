/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:08:41 by aperin            #+#    #+#             */
/*   Updated: 2022/12/01 17:29:40 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

#include <stdio.h> // TO REMOVE

# define NB_SPRITES 9
# define CELL_SIZE 32
# define ANIMATION_FRAMES 2500

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

typedef struct s_game
{
	char		**map;
	t_vector	size;
	t_vector	player;
	t_vector	enemy;
	int			food_left;
	int			score;
}				t_game;

typedef struct s_path
{
	t_vector		pos;
	struct s_path	*next;
}					t_path;

typedef struct s_img
{
	void		*img;
	t_vector	size;
	t_vector	pos;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	t_img	img[NB_SPRITES];
	t_game	*game;
	int		dir;
	int		enemy_dir;
}			t_mlx;

// Error
int			print_error(char *str, int call_perror);

// Input
int			check_input(int ac, char **av);

// Map
t_game		*init_game(char *file_name);
t_game		*free_game(t_game *game);
int			legal_map(t_game *game);
int			check_path(t_game *game);

// Map utils
void		set_player(t_game *game);
void		set_food_left(t_game *game);
void		get_legal_moves(char **map, t_vector player, int moves[4]);
int			equal_pos(t_vector pos1, t_vector pos2);
t_vector	make_move(t_vector curr_pos, int move);

// Path utils
t_path		*add_to_path(t_path *path, t_vector pos);
int			in_path(t_path *path, t_vector pos);
t_path		*push_path(t_path *allowed, t_path *visited);
t_path		*free_path(t_path *path);

// Game
void		play_game(t_game *game);

// Hooks
int			close_window(t_mlx *mlx);
int			key_pressed(int key, t_mlx *mlx);
int			sprite_animation(t_mlx	*mlx);

// Put to window
void		put_map(t_mlx *mlx);
void		put_image(t_mlx *mlx, int x, int y, int img);
void		put_score(t_mlx *mlx);

#endif