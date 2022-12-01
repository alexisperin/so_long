/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:28:16 by aperin            #+#    #+#             */
/*   Updated: 2022/12/01 13:44:17 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "ft_printf.h"
#include "libft.h"

int	close_window(t_mlx *mlx)
{
	free_game(mlx->game);
	mlx_destroy_image(mlx->mlx, mlx->img[0].img);
	mlx_destroy_image(mlx->mlx, mlx->img[1].img);
	mlx_destroy_image(mlx->mlx, mlx->img[2].img);
	mlx_destroy_image(mlx->mlx, mlx->img[3].img);
	mlx_destroy_image(mlx->mlx, mlx->img[4].img);
	mlx_destroy_image(mlx->mlx, mlx->img[5].img);
	mlx_destroy_image(mlx->mlx, mlx->img[6].img);
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(EXIT_SUCCESS);
}

static void	move(t_game *game, int move, int *dir)
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

int	key_pressed(int key, t_mlx *mlx)
{
	if (key == 126 || key == 13)
		move(mlx->game, 0, &(mlx->dir));
	else if (key == 125 || key == 1)
		move(mlx->game, 1, &(mlx->dir));
	else if (key == 123 || key == 0)
		move(mlx->game, 2, &(mlx->dir));
	else if (key == 124 || key == 2)
		move(mlx->game, 3, &(mlx->dir));
	else if (key == 53)
		close_window(mlx);
	if (mlx->game->map[mlx->game->player.y][mlx->game->player.x] == 'E'
		&& mlx->game->food_left == 0)
	{
		ft_printf("YOU WON !\n");
		close_window(mlx);
	}
	put_map(mlx);
	put_image(mlx, mlx->game->player.x, mlx->game->player.y, mlx->dir);
	return (0);
}

void	put_score(t_mlx *mlx)
{
	char	*score;
	char	*str;
	int		x;
	int		y;

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

int	sprite_animation(t_mlx	*mlx)
{
	static int	frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
	{
		mlx->img[mlx->dir].pos.x = mlx->game->player.x * CELL_SIZE;
		mlx->img[mlx->dir].pos.y = (mlx->game->player.y * CELL_SIZE) + 2;
	}
	else if (frame == ANIMATION_FRAMES * 2)
	{
		mlx->img[mlx->dir].pos.x = mlx->game->player.x * CELL_SIZE;
		mlx->img[mlx->dir].pos.y = mlx->game->player.y * CELL_SIZE;
		frame = 0;
	}
	else
		return (0);
	mlx_clear_window(mlx->mlx, mlx->window);
	put_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img[mlx->dir].img,
		mlx->img[mlx->dir].pos.x, mlx->img[mlx->dir].pos.y);
	put_score(mlx);
	return (0);
}
