/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:28:16 by aperin            #+#    #+#             */
/*   Updated: 2022/11/28 18:19:34 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "ft_printf.h"

int	close_window(t_mlx *mlx)
{
	free_game(mlx->game);
	mlx_destroy_image(mlx->mlx, mlx->img[0].img);
	mlx_destroy_image(mlx->mlx, mlx->img[1].img);
	mlx_destroy_image(mlx->mlx, mlx->img[2].img);
	mlx_destroy_image(mlx->mlx, mlx->img[3].img);
	mlx_destroy_image(mlx->mlx, mlx->img[4].img);
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(EXIT_SUCCESS);
}

static int	move(t_game *game, int move)
{
	int	ret;

	if (move == 0 && game->map[game->player.y - 1][game->player.x] != '1')
		game->player.y -= 1;
	else if (move == 1 && game->map[game->player.y + 1][game->player.x] != '1')
		game->player.y += 1;
	else if (move == 2 && game->map[game->player.y][game->player.x - 1] != '1')
	{
		game->player.x -= 1;
		ret = 1;
	}
	else if (move == 3 && game->map[game->player.y][game->player.x + 1] != '1')
	{
		game->player.x += 1;
		ret = 0;
	}
	else
		return (-1);
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->food_left -= 1;
		game->map[game->player.y][game->player.x] = '0';
	}
	game->score += 1;
	ft_printf("Number of moves: %d\n", game->score);
	return (ret);
}

static void	put_player(t_mlx *mlx)
{
	mlx->img[2].pos = mlx->img[0].pos;
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img[2].img,
		mlx->img[2].pos.x, mlx->img[2].pos.y);
	mlx->img[0].pos.x = CELL_SIZE * mlx->game->player.x;
	mlx->img[0].pos.y = CELL_SIZE * mlx->game->player.y;
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img[0].img,
		mlx->img[0].pos.x, mlx->img[0].pos.y);
}

int	key_pressed(int key, t_mlx *mlx)
{
	if (key == 126 || key == 13)
		move(mlx->game, 0);
	else if (key == 125 || key == 1)
		move(mlx->game, 1);
	else if (key == 123 || key == 0)
		mlx->dir = move(mlx->game, 2);
	else if (key == 124 || key == 2)
		mlx->dir = move(mlx->game, 3);
	else if (key == 53)
		close_window(mlx);
	printf("%d\n", mlx->dir);
	if (mlx->game->map[mlx->game->player.y][mlx->game->player.x] == 'E'
		&& mlx->game->food_left == 0)
	{
		ft_printf("YOU WON !\n");
		close_window(mlx);
	}
	put_player(mlx);
	return (0);
}

int	sprite_animation(t_mlx	*mlx)
{
	static int	frame;

	mlx->img[2].pos = mlx->img[0].pos;
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img[2].img,
		mlx->img[2].pos.x, mlx->img[2].pos.y);
	frame++;
	if (frame == ANIMATION_FRAMES)
		mlx->img[0].pos.y += 2;
	else if (frame == ANIMATION_FRAMES * 2)
	{
		mlx->img[0].pos.y -= 2;
		frame = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img[5].img,
		mlx->img[5].pos.x, mlx->img[5].pos.y);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img[0].img,
		mlx->img[0].pos.x, mlx->img[0].pos.y);
	return (0);
}
