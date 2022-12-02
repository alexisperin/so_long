/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:28:16 by aperin            #+#    #+#             */
/*   Updated: 2022/12/02 13:42:00 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "ft_printf.h"

int	close_window(t_mlx *mlx)
{
	int	i;

	i = 0;
	free_game(mlx->game);
	while (i < NB_SPRITES)
	{
		mlx_destroy_image(mlx->mlx, mlx->img[i].img);
		i++;
	}
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(EXIT_SUCCESS);
}

int	key_pressed(int key, t_mlx *mlx)
{
	if (key == 13)
		move_player(mlx->game, 0, &(mlx->dir));
	else if (key == 1)
		move_player(mlx->game, 1, &(mlx->dir));
	else if (key == 0)
		move_player(mlx->game, 2, &(mlx->dir));
	else if (key == 2)
		move_player(mlx->game, 3, &(mlx->dir));
	else if (key == 126 && mlx->game->enemy.x != 0 && mlx->game->enemy.y != 0)
		move_enemy(mlx->game, 0, &(mlx->enemy_dir));
	else if (key == 125 && mlx->game->enemy.x != 0 && mlx->game->enemy.y != 0)
		move_enemy(mlx->game, 1, &(mlx->enemy_dir));
	else if (key == 123 && mlx->game->enemy.x != 0 && mlx->game->enemy.y != 0)
		move_enemy(mlx->game, 2, &(mlx->enemy_dir));
	else if (key == 124 && mlx->game->enemy.x != 0 && mlx->game->enemy.y != 0)
		move_enemy(mlx->game, 3, &(mlx->enemy_dir));
	else if (key == 53)
		close_window(mlx);
	update_window(mlx);
	return (0);
}

static void	sprite_animation2(t_mlx	*mlx)
{
	mlx_clear_window(mlx->mlx, mlx->window);
	put_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img[mlx->dir].img,
		mlx->img[mlx->dir].pos.x, mlx->img[mlx->dir].pos.y);
	if (mlx->game->enemy.x != 0 && mlx->game->enemy.y != 0)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->img[7 + mlx->enemy_dir].img,
			mlx->img[7 + mlx->enemy_dir].pos.x,
			mlx->img[7 + mlx->enemy_dir].pos.y);
}

int	sprite_animation(t_mlx	*mlx)
{
	static int	frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
	{
		mlx->img[mlx->dir].pos.x = mlx->game->player.x * CELL_SIZE;
		mlx->img[mlx->dir].pos.y = (mlx->game->player.y * CELL_SIZE) + 2;
		mlx->img[7 + mlx->enemy_dir].pos.x = mlx->game->enemy.x * CELL_SIZE;
		mlx->img[7 + mlx->enemy_dir].pos.y = mlx->game->enemy.y * CELL_SIZE;
		mlx->img[7 + mlx->enemy_dir].pos.y += 2;
	}
	else if (frame == ANIMATION_FRAMES * 2)
	{
		mlx->img[mlx->dir].pos.x = mlx->game->player.x * CELL_SIZE;
		mlx->img[mlx->dir].pos.y = mlx->game->player.y * CELL_SIZE;
		mlx->img[7 + mlx->enemy_dir].pos.x = mlx->game->enemy.x * CELL_SIZE;
		mlx->img[7 + mlx->enemy_dir].pos.y = mlx->game->enemy.y * CELL_SIZE;
		frame = 0;
	}
	else
		return (0);
	sprite_animation2(mlx);
	return (0);
}
