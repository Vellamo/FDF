/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wireframe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:51:49 by lharvey           #+#    #+#             */
/*   Updated: 2020/02/18 11:51:53 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Converts a string of words into an array of integers
*/ 
static void	*words_to_int(char *string, int words, t_projection *t_coordinates)	
{
	char	**string_array;
	int		x;
	
	if (!string || !words || !t_coordinates)
		return (0);
	x = 0;
	string_array = ft_strsplit(string, ' ');
	while (x != words)
	{
		t_coordinates[x].z = ft_atoi(string_array[x]);
		++x;
	}
	while (--words >= 0)
		ft_memdel((void **)string_array++);
	return ;
}

/* 
** Variation of check_wireframe, this one uses information to convert input
** data, so that it conforms to the t_wiremap datatype for later use.
*/
t_wiremap	*convert_wireframe(int fd, t_wiremap *wire_map)
{
	char			*line;
	unsigned int	y;
	
	y = 0;
	while ((get_next_line(fd, &line)) != 0)
	{
		words_to_int(line, wire_map->width, wire_map->map_prj[y]);
		++y;
		free(line);
		*line = '\0';
	}
	return (wire_map);
}
