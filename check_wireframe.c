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

#include "libft/libft.h"
#include "fdf.h"

/* 
** Just initilises the wireframe struct
*/ 
static t_wiremap	*initialise_wireframe(t_wiremap *wire_map, int width, int height)
{
	wire_map = (t_wiremap*)malloc(sizeof(t_wiremap));
	wire_map->width = width;
	wire_map->height = height;
}

/* 
** Counts the amount of 'words' from within the input file. 
*/
int					word_count(char *string)
{
	int ret_val;

	ret_val = 0;
	while (*string != '\0' || *string != '\n')
	{
		if (ft_isascii(*string) == 1)
		{
			++ret_val;
			while (ft_isascii(*(string + 1)) == 1)
				string++;
		}
		string++;
	}
	return (ret_val);
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
	while ((get_next_line(fd, &line)) != 0)
	{
		if ((wire_x = word_count(line)) == 0)
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
