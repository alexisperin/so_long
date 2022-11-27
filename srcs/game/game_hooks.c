/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:28:16 by aperin            #+#    #+#             */
/*   Updated: 2022/11/27 17:43:47 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	close_window(t_mlx *mlx)
{
	free_game(mlx->game);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(EXIT_SUCCESS);
}

int	key_pressed(int key, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->window);
	if (key == 124 || key == 2)
		mlx->img.pos.x += mlx->img.size.x;
	else if (key == 123 || key == 0)
		mlx->img.pos.x -= mlx->img.size.x;
	else if (key == 125 || key == 1)
		mlx->img.pos.y += mlx->img.size.y;
	else if (key == 126 || key == 13)
		mlx->img.pos.y -= mlx->img.size.y;
	else if (key == 53)
		close_window(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img,
							mlx->img.pos.x, mlx->img.pos.y);
	return (0);
}

int	sprite_animation(t_mlx	*mlx)
{
	static int	frame;

	mlx_clear_window(mlx->mlx, mlx->window);
	frame++;
	if (frame == ANIMATION_FRAMES)
		mlx->img.pos.y += 2;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		mlx->img.pos.y -= 2;
		frame = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img,
							mlx->img.pos.x, mlx->img.pos.y);
	return (0);
}