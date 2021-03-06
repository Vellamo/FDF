/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:17:34 by lharvey           #+#    #+#             */
/*   Updated: 2020/02/18 10:19:54 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>
# define WINDOW_HEIGHT 900
# define WINDOW_WIDTH 1600
typedef struct	s_projection
{
	int				x;
	int				y;
	int				z;
}				t_projection;
typedef struct	s_wiremap
{
	int				width;
	int				height;
	t_projection	**map_prj;
}				t_wiremap;
t_wiremap	*check_wireframe(int fd);
t_wiremap	*convert_wireframe(int fd, t_wiremap *wire_map);
void draw_wireframe(t_wiremap *wire_map);
typedef struct	s_mlx
{
	void			*mlx_ptr; /* connection login to the graphical server */
	void			*win_ptr; /* an identifier for the window (MiniLibX can open many) */
	void			*mlx_image; /* An image that can be given to the window */
	int				pixel_bits;
	int				line_pixels;
	int				endian;
	int				*buffer_32bit;
}				t_mlx;
typedef	struct	s_bresenheim
{
	int	delta_x;
	int delta_y;
	int	signal_x;
	int	signal_y;
	int	error_x;
	int	error_y;
}					t_bresenheim;

#endif
