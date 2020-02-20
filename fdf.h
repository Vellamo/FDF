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
void draw_wireframe();
#endif
