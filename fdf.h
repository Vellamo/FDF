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

t_wiremap	*check_wireframe(int fd);
int			word_count(char *string);
typedef struct s_wiremap
{
	unsigned int	x;
	unsigned int	y;
	int				**map_data;
}					t_wiremap;
t_wiremap	*convert_wireframe(int fd, t_wiremap *wire_map)

#endif
