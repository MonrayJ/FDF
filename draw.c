/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:37:57 by mjacobs           #+#    #+#             */
/*   Updated: 2018/08/19 16:03:27 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_liney(double b[2], double g[2], t_mlx *mlx, int c)
{
	double	m;
	double	s[2];
	double	e[2];

	s[0] = (b[1] < g[1]) ? b[0] : g[0];
	s[1] = (b[1] < g[1]) ? b[1] : g[1];
	e[0] = (b[1] < g[1]) ? g[0] : b[0];
	e[1] = (b[1] < g[1]) ? g[1] : b[1];
	m = (e[0] - s[0]) / (e[1] - s[1]);
	while (s[1] <= e[1])
	{
		s[0] += m;
		s[1] += 1;
		if ((s[0] >= 0 && s[0] <= 900) && (s[1] >= 0 && s[1] <= 900))
			put_pixel_image(mlx, s[0], s[1], c);
	}
}

void	draw_line(double b[2], double g[2], t_mlx *mlx, int c)
{
	double	m;
	double	s[2];
	double	e[2];

	s[0] = (b[0] < g[0]) ? b[0] : g[0];
	s[1] = (b[0] < g[0]) ? b[1] : g[1];
	e[0] = (b[0] < g[0]) ? g[0] : b[0];
	e[1] = (b[0] < g[0]) ? g[1] : b[1];
	m = (e[1] - s[1]) / (e[0] - s[0]);
	if (m < -1 || m > 1)
	{
		draw_liney(b, g, mlx, c);
		return ;
	}
	while (s[0] <= e[0])
	{
		s[0] += 1;
		s[1] += m;
		if ((s[0] >= 0 && s[0] <= 900) && (s[1] >= 0 && s[1] <= 900))
			put_pixel_image(mlx, s[0], s[1], c);
	}
}

void	draw_grid(t_mlx *mlx, int x, int y)
{
	double	points[2][2];

	while (++y < mlx->m_y)
	{
		x = -1;
		while (++x < mlx->m_x)
		{
			points[0][0] = mlx->map[y][x][0] * mlx->scale + mlx->x_off;
			points[0][1] = mlx->map[y][x][1] * mlx->scale + mlx->y_off;
			if (x < (mlx->m_x - 1))
			{
				points[1][0] = mlx->map[y][x + 1][0] * mlx->scale + mlx->x_off;
				points[1][1] = mlx->map[y][x + 1][1] * mlx->scale + mlx->y_off;
				draw_line(points[0], points[1], mlx, 0xffff);
			}
			if (y < (mlx->m_y - 1))
			{
				points[1][0] = mlx->map[y + 1][x][0] * mlx->scale + mlx->x_off;
				points[1][1] = mlx->map[y + 1][x][1] * mlx->scale + mlx->y_off;
				draw_line(points[0], points[1], mlx, 0xffffff);
			}
		}
	}
}
