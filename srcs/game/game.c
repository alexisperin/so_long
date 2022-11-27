/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:26:37 by aperin            #+#    #+#             */
/*   Updated: 2022/11/27 17:42:06 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

t_img	new_sprite(void *mlx, char	*file_path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, file_path, &img.size.x, &img.size.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
									&img.line_length, &img.endian);
	return (img);
}

void	play_game(t_game *game)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return ;
	mlx.window = mlx_new_window(mlx.mlx, 50 * game->size.x,
								50 * game->size.y, "so_long");
	if (!mlx.window)
		return ;
	mlx.game = game;
	mlx.img = new_sprite(mlx.mlx, "sprites/monster.xpm");
	mlx.img.pos.x = 0;
	mlx.img.pos.y = 0;
	mlx.wall = new_sprite(mlx.mlx, "sprites/rock.xpm");
	mlx.wall.pos.x = 0;
	mlx.wall.pos.y = 0;
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img.img, mlx.img.pos.x,
							mlx.img.pos.y);
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.wall.img, mlx.wall.pos.x,
							mlx.wall.pos.y);
	mlx_hook(mlx.window, 17, 0, close_window, &mlx);
	mlx_key_hook (mlx.window, key_pressed, &mlx);
	// mlx_loop_hook(mlx.mlx, sprite_animation, &mlx);
	mlx_loop(mlx.mlx);
}