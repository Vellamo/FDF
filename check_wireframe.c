/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wireframe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:42:35 by lharvey           #+#    #+#             */
/*   Updated: 2020/02/10 15:42:41 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
** Just initilises the wireframe struct. We allocate basic X and Y values
** however, these aren't ever accessed. They are modified later... 
*/ 
static t_wiremap	*initialise_wireframe(t_wiremap *wire_map, int width, int height)
{
	int x;
	int y;

	x = -1;
	y = 0;
	wire_map = (t_wiremap*)malloc(sizeof(t_wiremap));
	wire_map->width = width;
	wire_map->height = height;
	wire_map->map_prj = (t_projection **)malloc(sizeof(t_projection *) * (height * width));
	while(x <= width && y <= height)
	{
		while (++x <= width)
		{
			wire_map->map_prj[height][width].x = x;
			wire_map->map_prj[height][width].y = y;
			wire_map->map_prj[height][width].z = 0;
		}
		x = -1;
		++y; 
	}
	return (wire_map);
}

/* 
** Counts the amount of 'words' from within the input file. 
** Char c is the delimiter
*/
static int			word_count(char *string, char c)
{
	int word_count;
	int	i;
	if (!string)
		return (-1);
	word_count = (*string == c) ? 0 : 1;
	i = (word_count == 0) ? 0 : 1;
	while (string[i])
	{
		while (string[i] == c && (string[(i + 1)] != '\0'))                                                                                     
			i++;
		if (string[i] != c && (string[(i + 1)]) == c)
			++word_count;
		++i;
	}
	return (word_count);
}

/* 
** Function to check the 'width' (x) and 'height' (y) of a map
** returns a value >0 if the input is valid, else -1.
*/
t_wiremap			*check_wireframe(int fd)
{
	int			wire_y;
	int			wire_x;
	char		*line;
	int			width_check;
	t_wiremap	*wire_map;

	wire_y = 0;
	wire_x = 0;
	width_check = 0;
	wire_map = NULL;
	while ((get_next_line(fd, &line)) != 0)
	{
		if ((wire_x = word_count(line, ' ')) == 0)
		{
			ft_memdel((void**)&line);
			return (NULL);
		}
		if (wire_y != 0)
		{
			if (width_check != wire_x)
			{
				ft_memdel((void**)&line);
				return (NULL);
			}
		}
		++wire_y;
		width_check = wire_x;
	}
	wire_map = initialise_wireframe(wire_map, wire_x, wire_y);
	return (wire_map);
}
