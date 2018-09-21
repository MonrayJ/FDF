/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:50:33 by mjacobs           #+#    #+#             */
/*   Updated: 2018/08/20 10:39:57 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_image(t_mlx *mlx, int x, int y, int c)
{
	int i;

	i = x * (mlx->bpp / 8) + y * mlx->ll;
	if (x >= 0 && x < 900 && y >= 0 && y < 900)
	{
		mlx->data[i] = c & 0x000000ff;
		mlx->data[i + 1] = (c & 0x0000ff00) / 0x100;
		mlx->data[i + 2] = (c & 0x00ff0000) / 0x10000;
	}
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	int		fd;

	if (ac == 2)
	{
		mlx.x_off = 450;
		mlx.y_off = 450;
		fd = open(av[1], O_RDONLY);
		ft_get_size(fd, &mlx.m_y, &mlx.m_x);
		close(fd);
		mlx.mlx = mlx_init();
		mlx.window = mlx_new_window(mlx.mlx, 900, 900, "Test");
		mlx.image = mlx_new_image(mlx.mlx, 900, 900);
		mlx.scale = 900 / (double)((mlx.m_y > mlx.m_x) ? mlx.m_y : mlx.m_x);
		mlx.data = (unsigned char*)mlx_get_data_addr(mlx.image,
			&mlx.bpp, &mlx.ll, &mlx.end);
		fd = open(av[1], O_RDONLY);
		mlx.map = read_file(fd, mlx.m_y, mlx.m_x);
		draw_grid(&mlx, -1, -1);
		mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image, 0, 0);
		mlx_hook(mlx.window, 2, 0, hook_keydown, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		ft_putendl("Usage: <Program Name> <Path to Map>");
}
