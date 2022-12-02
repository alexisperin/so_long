/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:26:37 by aperin            #+#    #+#             */
/*   Updated: 2022/12/02 13:31:51 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"

void	put_image(t_mlx *mlx, int x, int y, int img)
{
	if ((img == 7 || img == 8) && mlx->enemy_dir == -1)
		return ;
	mlx->img[img].pos.x = x * CELL_SIZE;
	mlx->img[img].pos.y = y * CELL_SIZE;
	if (img == 4)
	{
		mlx->img[img].pos.x += CELL_SIZE / 4;
		mlx->img[img].pos.y += CELL_SIZE / 4;
	}
	if (img == 5 || img == 6)
	{
		mlx->img[img].pos.x += CELL_SIZE / 10;
		mlx->img[img].pos.y += CELL_SIZE / 10;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img[img].img,
		mlx->img[img].pos.x, mlx->img[img].pos.y);
}

static void	put_map_last_row(t_mlx *mlx, int y)
{
	int		x;
	char	*score;
	char	*str;

	x = 0;
	while (x < mlx->game->size.x)
	{
		put_image(mlx, x, y, 2);
		x++;
	}
	score = ft_itoa(mlx->game->score);
	str = ft_strjoin("Score: ", score);
	free(score);
	if (!str)
		return ;
	x = (mlx->game->size.x / 2) * CELL_SIZE - (CELL_SIZE);
	y = mlx->game->size.y * CELL_SIZE + (CELL_SIZE / 2);
	mlx_string_put(mlx->mlx, mlx->window, x, y, 1000, str);
	free(str);
}

void	put_map(t_mlx *mlx)
{
	char	**map;
	int		x;
	int		y;

	map = mlx->game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			put_image(mlx, x, y, 2);
			if (map[y][x] == '1')
				put_image(mlx, x, y, 3);
			else if (map[y][x] == 'C')
				put_image(mlx, x, y, 4);
			else if (map[y][x] == 'E')
				put_image(mlx, x, y, 5 + (mlx->game->food_left == 0));
			x++;
		}
		y++;
	}
	put_map_last_row(mlx, y);
}

void	play_game(t_game *game)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return ;
	mlx.window = mlx_new_window(mlx.mlx, CELL_SIZE * game->size.x,
			CELL_SIZE * (game->size.y + 1), "so_long");
	if (!mlx.window)
		return ;
	mlx.game = game;
	mlx.dir = 0;
	mlx.enemy_dir = 0;
	if (game->enemy.x == 0 && game->enemy.y == 0)
		mlx.enemy_dir = -1;
	if (!load_sprites(&mlx))
		return ;
	put_map(&mlx);
	put_image(&mlx, game->player.x, game->player.y, 0);
	put_image(&mlx, game->enemy.x, game->enemy.y, 7);
	mlx_hook(mlx.window, 17, 0, close_window, &mlx);
	mlx_key_hook (mlx.window, key_pressed, &mlx);
	mlx_loop_hook(mlx.mlx, sprite_animation, &mlx);
	mlx_loop(mlx.mlx);
}
