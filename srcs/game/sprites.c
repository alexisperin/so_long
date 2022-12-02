/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:17:34 by aperin            #+#    #+#             */
/*   Updated: 2022/12/02 13:32:50 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

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

static int	protect_images(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < NB_SPRITES)
	{
		if (!mlx->img[i].img)
		{
			close_window(mlx);
			i = 0;
			while (i < NB_SPRITES)
			{
				if (mlx->img[i].img)
					mlx_destroy_image(mlx->mlx, mlx->img[i].img);
				i++;
			}
			mlx_destroy_window(mlx->mlx, mlx->window);
			return (0);
		}
		i++;
	}
	return (1);
}

int	load_sprites(t_mlx *mlx)
{
	mlx->img[0] = new_sprite(mlx->mlx, "sprites/monster_right.xpm");
	mlx->img[1] = new_sprite(mlx->mlx, "sprites/monster_left.xpm");
	mlx->img[2] = new_sprite(mlx->mlx, "sprites/back.xpm");
	mlx->img[3] = new_sprite(mlx->mlx, "sprites/rock.xpm");
	mlx->img[4] = new_sprite(mlx->mlx, "sprites/gem.xpm");
	mlx->img[5] = new_sprite(mlx->mlx, "sprites/safe1.xpm");
	mlx->img[6] = new_sprite(mlx->mlx, "sprites/safe2.xpm");
	mlx->img[7] = new_sprite(mlx->mlx, "sprites/enemy_right.xpm");
	mlx->img[8] = new_sprite(mlx->mlx, "sprites/enemy_left.xpm");
	return (protect_images(mlx));
}
