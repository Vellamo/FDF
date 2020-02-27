/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:57:34 by lharvey           #+#    #+#             */
/*   Updated: 2020/02/06 16:13:55 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>

static int				open_file(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write(2, "Usage: ./fdf [target_file]\n", 28);
		exit (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "Open failed to work with file\n", 31);
		exit (-1);
	}
	return (fd);
}

int main(int argc, char **argv)
{
	int				fd;
	t_wiremap		*wire_map;
	
	wire_map = NULL;
	fd = open_file(argc, argv);
	if ((wire_map = check_wireframe(fd)) == NULL)
	{
		write(2, "Invalid file was given as a parameter!\n", 40);
		close(fd);
		exit (-1);
	}
	else
	{
		close(fd);
		fd = open_file(argc, argv);
		convert_wireframe(fd, wire_map);
	}
	close(fd);
	draw_wireframe(wire_map);
}
