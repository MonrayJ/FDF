/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:55:49 by mjacobs           #+#    #+#             */
/*   Updated: 2018/08/19 17:32:05 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_mlx *mlx, double angle)
{
	double	temp;
	int		y;
	int		x;

	y = 0;
	while (y < mlx->m_y)
	{
		x = 0;
		while (x < mlx->m_x)
		{
			temp = cos(angle) * mlx->map[y][x][1] - sin(angle) *
				mlx->map[y][x][2];
			mlx->map[y][x][2] = cos(angle) * mlx->map[y][x][2] + sin(angle)
				* mlx->map[y][x][1];
			mlx->map[y][x][1] = temp;
			++x;
		}
		++y;
	}
}

void	rotate_y(t_mlx *mlx, double angle)
{
	double	temp;
	int		y;
	int		x;

	y = 0;
	while (y < mlx->m_y)
	{
		x = 0;
		while (x < mlx->m_x)
		{
			temp = cos(angle) * mlx->map[y][x][0] - sin(angle) *
				mlx->map[y][x][2];
			mlx->map[y][x][2] = cos(angle) * mlx->map[y][x][2] + sin(angle)
				* mlx->map[y][x][0];
			mlx->map[y][x][0] = temp;
			++x;
		}
		++y;
	}
}

void	rotate_z(t_mlx *mlx, double angle)
{
	double	temp;
	int		y;
	int		x;

	y = 0;
	while (y < mlx->m_y)
	{
		x = 0;
		while (x < mlx->m_x)
		{
			temp = cos(angle) * mlx->map[y][x][1] - sin(angle) *
				mlx->map[y][x][0];
			mlx->map[y][x][0] = cos(angle) * mlx->map[y][x][0] + sin(angle)
				* mlx->map[y][x][1];
			mlx->map[y][x][1] = temp;
			++x;
		}
		++y;
	}
}

void	clear_image(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < 900)
	{
		x = -1;
		while (++x < 900)
			put_pixel_image(mlx, x, y, 0);
		y++;
	}
}

int		hook_keydown(int key, t_mlx *mlx)
{
	clear_image(mlx);
	(void)mlx;
	if (key == 69)
		mlx->scale *= 1.5;
	if (key == 78 && mlx->scale > 0.0001)
		mlx->scale /= 1.5;
	if (key == 13)
		rotate_x(mlx, 10 * M_PI / 180);
	if (key == 1)
		rotate_x(mlx, -10 * M_PI / 180);
	if (key == 0)
		rotate_y(mlx, 10 * M_PI / 180);
	if (key == 2)
		rotate_y(mlx, -10 * M_PI / 180);
	if (key == 12)
		rotate_z(mlx, 10 * M_PI / 180);
	if (key == 14)
		rotate_z(mlx, -10 * M_PI / 180);
	if (key == 53)
		exit(EXIT_SUCCESS);
	draw_grid(mlx, -1, -1);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
	return (0);
}
