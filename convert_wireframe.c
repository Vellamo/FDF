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

#include "libft/libft.h"
#include "fdf.h"
#include <stdlib.h>

/*
** Converts a string of words into an array of integers
*/ 
static int	*words_to_int(char *string, int words)	
{
	char	**string_array;
	int		*int_array;
	int		i;
	
	if (!string || !words)
		return (0);
	i = 0;
	string_array = ft_strsplit(string, ' ');
	int_array = (int*)malloc(sizeof(int) * words);
	while (i != words)
	{
		int_array[i] = ft_atoi(string_array[i]);
		++i;
	}
	while (string_array)
		ft_memdel((void **)string_array++);
	return (int_array);
}

/* 
** Variation of check_wireframe, this one uses information to convert input
** data, so that it conforms to the t_wiremap datatype for later use.
*/
t_wiremap	*convert_wireframe(int fd, t_wiremap *wire_map)
{
	char			*line;
	unsigned int	i;
	int				**map_data;
	
	i = 0;
	while ((get_next_line(fd, &line)) != 0)
	{
		*map_data[i] = words_to_int(line, wire_map->width);
		++i;
	}
	ft_memdel((void**)&line);
	return (wire_map);
}
