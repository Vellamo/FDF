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
# define WINDOW_HEIGHT 900
# define WINDOW_WIDTH 1600
typedef struct s_wiremap
{
	unsigned int	width;
	unsigned int	height;
	int				**map_data;
}					t_wiremap;
t_wiremap	*check_wireframe(int fd);
t_wiremap	*convert_wireframe(int fd, t_wiremap *wire_map);
void draw_wireframe(t_wiremap *wire_map);
typedef struct s_mlx
{
	void			*mlx_ptr; /* connection login to the graphical server */
	void			*win_ptr; /* an identifier for the window (MiniLibX can open many) */
	void			*mlx_image; /* An image that can be given to the window */
	int				pixel_bits;
	int				line_bytes;
	int				endian;
	int				*buffer_32bit;
}					t_mlx;
#endif
