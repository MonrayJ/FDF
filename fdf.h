/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:53:19 by mjacobs           #+#    #+#             */
/*   Updated: 2018/08/19 17:50:52 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

/*
**coment
*/

typedef struct	s_mlx
{
	double			scale;
	double			x_off;
	double			y_off;
	void			*mlx;
	void			*window;
	int				m_x;
	int				m_y;
	void			*image;
	unsigned char	*data;
	int				bpp;
	int				ll;
	int				end;
	double			***map;
}				t_mlx;

void			put_pixel_image(t_mlx *mlx, int x, int y, int c);
double			***read_file(int fd, int m_x, int m_y);
double			***ft_map(char	***str, int m_y, int m_x);
void			ft_get_size(int fd, int *y, int *x);
void			draw_grid(t_mlx *mlx, int x, int y);
void			draw_right(double *s, double *r);
void			draw_down(double *s, double *d);
int				hook_keydown(int key, t_mlx *mlx);

#endif
