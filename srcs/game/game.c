/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:26:37 by aperin            #+#    #+#             */
/*   Updated: 2022/12/01 10:34:52 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static int	protect_images(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < NB_SPRITES)
	{
		if (!mlx->img[i].img)
		{
			i = 0;
			while (i < NB_SPRITES)
			{
				if (mlx->img[i].img)
					mlx_destroy_image(mlx->mlx, mlx->img[i].img);
				i++;
			}
			mlx_destroy_window(mlx->mlx, mlx->window);
			return (1);
		}
		i++;
	}
	return (0);
}

static t_img	new_sprite(void *mlx, char	*file_path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, file_path, &img.size.x, &img.size.y);
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

void	put_image(t_mlx *mlx, int x, int y, int img)
{
	mlx->img[img].pos.x = x * CELL_SIZE;
	mlx->img[img].pos.y = y * CELL_SIZE;
	if (img == 4)
	{
		mlx->img[img].pos.x += CELL_SIZE / 4;
		mlx->img[img].pos.y += CELL_SIZE / 4;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img[img].img,
		mlx->img[img].pos.x, mlx->img[img].pos.y);
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
}

void	play_game(t_game *game)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return ;
	mlx.window = mlx_new_window(mlx.mlx, CELL_SIZE * game->size.x,
			CELL_SIZE * game->size.y, "so_long");
	if (!mlx.window)
		return ;
	mlx.game = game;
	mlx.dir = 0;
	mlx.img[0] = new_sprite(mlx.mlx, "sprites/monster_right.xpm");
	mlx.img[1] = new_sprite(mlx.mlx, "sprites/monster_left.xpm");
	mlx.img[2] = new_sprite(mlx.mlx, "sprites/back.xpm");
	mlx.img[3] = new_sprite(mlx.mlx, "sprites/rock.xpm");
	mlx.img[4] = new_sprite(mlx.mlx, "sprites/gem.xpm");
	mlx.img[5] = new_sprite(mlx.mlx, "sprites/safe.xpm");
	mlx.img[6] = new_sprite(mlx.mlx, "sprites/safe_open.xpm");
	if (protect_images(&mlx))
		return ;
	put_map(&mlx);
	put_image(&mlx, game->player.x, game->player.y, 0);
	mlx_hook(mlx.window, 17, 0, close_window, &mlx);
	mlx_key_hook (mlx.window, key_pressed, &mlx);
	mlx_loop_hook(mlx.mlx, sprite_animation, &mlx);
	mlx_loop(mlx.mlx);
}
