/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:34:33 by aperin            #+#    #+#             */
/*   Updated: 2022/12/02 13:35:40 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "ft_printf.h"

void	move_player(t_game *game, int move, int *dir)
{
	if (move == 0 && game->map[game->player.y - 1][game->player.x] != '1')
		game->player.y -= 1;
	else if (move == 1 && game->map[game->player.y + 1][game->player.x] != '1')
		game->player.y += 1;
	else if (move == 2 && game->map[game->player.y][game->player.x - 1] != '1')
	{
		game->player.x -= 1;
		*dir = 1;
	}
	else if (move == 3 && game->map[game->player.y][game->player.x + 1] != '1')
	{
		game->player.x += 1;
		*dir = 0;
	}
	else
		return ;
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->food_left -= 1;
	}
	game->score += 1;
	ft_printf("Number of moves: %d\n", game->score);
}

void	move_enemy(t_game *game, int move, int *dir)
{
	if (move == 0 && game->map[game->enemy.y - 1][game->enemy.x] != '1')
		game->enemy.y -= 1;
	else if (move == 1 && game->map[game->enemy.y + 1][game->enemy.x] != '1')
		game->enemy.y += 1;
	else if (move == 2 && game->map[game->enemy.y][game->enemy.x - 1] != '1')
	{
		game->enemy.x -= 1;
		*dir = 1;
	}
	else if (move == 3 && game->map[game->enemy.y][game->enemy.x + 1] != '1')
	{
		game->enemy.x += 1;
		*dir = 0;
	}
	else
		return ;
}

void	update_window(t_mlx *mlx)
{
	if (mlx->game->map[mlx->game->player.y][mlx->game->player.x] == 'E'
		&& mlx->game->food_left == 0)
	{
		ft_printf("YOU WON !\n");
		close_window(mlx);
	}
	if (equal_pos(mlx->game->player, mlx->game->enemy))
	{
		ft_printf("YOU DIED, LOSER !\n");
		close_window(mlx);
	}
	put_map(mlx);
	put_image(mlx, mlx->game->player.x, mlx->game->player.y, mlx->dir);
	if (mlx->game->enemy.x != 0 && mlx->game->enemy.y != 0)
		put_image(mlx, mlx->game->enemy.x, mlx->game->enemy.y,
			7 + mlx->enemy_dir);
}
