/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 12:14:41 by mjacobs           #+#    #+#             */
/*   Updated: 2018/08/20 10:39:52 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_size(int fd, int *y, int *x)
{
	char	*line;
	char	**str;

	*y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		*x = 0;
		str = ft_strsplit(line, ' ');
		free(line);
		while (str[*x])
		{
			free(str[*x]);
			(*x)++;
		}
		free(str);
		(*y)++;
	}
}

double	***malloc_3d(int m_x, int m_y)
{
	double	***map;
	int		y;
	int		x;

	y = 0;
	x = 0;
	map = (double***)malloc(sizeof(double**) * m_y);
	while (y < m_y)
	{
		map[y] = (double**)malloc(sizeof(double*) * m_x);
		x = 0;
		while (x < m_x)
		{
			map[y][x] = (double*)malloc(sizeof(double) * 3);
			x++;
		}
		y++;
	}
	return (map);
}

double	***ft_map(char ***str, int m_x, int m_y)
{
	int		y;
	int		x;
	double	***map;

	map = malloc_3d(m_x, m_y);
	y = 0;
	while (y < m_y)
	{
		x = 0;
		while (x < m_x)
		{
			map[y][x][0] = (x - (m_x / 2));
			map[y][x][1] = (y - (m_y / 2));
			map[y][x][2] = ft_atoi(str[y][x]);
			free(str[y][x]);
			x++;
		}
		free(str[y]);
		y++;
	}
	free(str);
	return (map);
}

double	***read_file(int fd, int m_y, int m_x)
{
	int		i;
	char	***str;
	char	*line;
	double	***map;

	i = 0;
	str = (char***)malloc(sizeof(char**) * m_y);
	while (get_next_line(fd, &line) > 0)
	{
		str[i++] = ft_strsplit(line, ' ');
		free(line);
	}
	map = ft_map(str, m_x, m_y);
	return (map);
}
