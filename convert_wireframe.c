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
** Adds one array of integers to another, using int_1 as the pre
*/
static int	*int_join(int const *int_1, int const *int_2)
{
	int				*fresh;
	unsigned int	total_ints;

	if (!int_1 || !int_2)
		return (0);
	total_ints = (ft_strlen(int_1)) + (ft_strlen(int_2));
	if (!(fresh = (int *)malloc((total_ints + 1) * (sizeof(int *)))))
		return (0);
	ft_strcpy(fresh, int_1);
	ft_strcat(fresh, int_2);
	return (fresh);
}

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
		ft_memdel(string_array++);
	return (int_array);
}

/* 
** Variation of check_wireframe, this one uses information to convert input
** data, so that it conforms to the t_wiremap datatype for later use.
*/
t_wiremap	*convert_wireframe(const int fd)
{
	t_wiremap		*wire_map;
	char			*many_lines;
	char			*line;
	unsigned int	width;

	wire_map = (t_wiremap*)malloc(sizeof(t_wiremap));
	wire_map->data = 0;

	*line = 0;
	*many_lines = 0;
	while ((get_next_line(fd, &line)) != 0)
	{
		if (many_lines = 0)
			width = word_count(*line);
		many_lines = ft_strjoin(many_lines, line);
	}
	wire_map->data = int_join(wire_map->data, words_to_int(many_lines, width));
	ft_memdel(&line);
	ft_memdel(&many_lines);
	return (wire_map);
}