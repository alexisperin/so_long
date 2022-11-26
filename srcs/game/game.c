/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:26:37 by aperin            #+#    #+#             */
/*   Updated: 2022/11/26 14:31:52 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	close_window(t_mlx *mlx)
{
	free_game(mlx->game);
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(EXIT_SUCCESS);
}

void	play_game(t_game *game)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return ;
	mlx.window = mlx_new_window(mlx.mlx, 50 * game->width, 50 * game->height, "so_long");
	if (!mlx.window)
		return ;
	mlx.game = game;
	mlx.img.img = mlx_xpm_file_to_image(mlx.mlx, "sprites/monster.xpm", &mlx.img.width, &mlx.img.height);
	mlx_hook(mlx.window, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
}