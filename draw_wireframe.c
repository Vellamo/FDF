/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:40:42 by lharvey           #+#    #+#             */
/*   Updated: 2020/02/20 14:40:43 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

static int		key_press(int keycode)
{
	ft_putnbr(keycode);
	if (keycode == 53)
		exit(0);
	return (0);
	// UP: 126
	// RIGHT: 124
	// DOWN: 125
	// LEFT: 123

	// W: 13
	// S: 1
	// A: 0 
	// D: 2
}

static t_mlx	*initialise_minilibx(t_mlx *mlx_data)
{
	if(!(mlx_data->mlx_ptr = mlx_init())) //Handling for init returning NULL
		exit (-1);
	if (!(mlx_data->win_ptr = (void *)mlx_new_window(mlx_data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Hive_Wireframe")))
		exit (-1);
	if (!(mlx_data->mlx_image = (void *)mlx_new_image(mlx_data->mlx_ptr, WINDOW_WIDTH * 2, WINDOW_HEIGHT * 2)))
		exit (-1);
	mlx_data->buffer_32bit = (int *)mlx_get_data_addr(mlx_data->mlx_image, &(mlx_data->pixel_bits), &(mlx_data->line_pixels), &(mlx_data->endian));
	mlx_data->line_pixels /= 4;

	return (mlx_data);
}

/* Bresenheim psuedocode */

static void		bresenheim_algo(t_mlx *mlx_data, t_projection *point_src, t_projection *point_dst, int colour)
{
//	function line(x0, y0, x1, y1)
	int	i;
	int	x;
	int y;
	int	delta_x;
	int delta_y;
	int	signal_x;
	int	signal_y;
	int	error_x;
	int	error_y;
	
	delta_x = 0;
	delta_y = 0;
	signal_x = 0;
	signal_y = 0;
	error_x = 0;
	error_y = 0;
	x = 0;
	y = 0;

// BRESENHEIM PSUEDOCODE : 
// plotLine(int x0, int y0, int x1, int y1)
//     dx =  abs(x1-x0);
//     sx = x0<x1 ? 1 : -1;
//     dy = -abs(y1-y0);
//     sy = y0<y1 ? 1 : -1;
//     err = dx+dy;  /* error value e_xy */
	delta_x = abs(point_src->x - point_dst->x);
	signal_x = (point_src->x < point_dst->x) ? 1 : -1;
	delta_y = abs(point_src->y - point_dst->y);
	signal_y = (point_src->y < point_dst->y) ? 1 : -1;
 	error_x = (delta_x > delta_y ? delta_x : -delta_y) / 2;
	x = point_src->x;
	y = point_src->y;

//     while (true)   /* loop */
//         plot(x0, y0);
//         if (x0==x1 && y0==y1) break;
//         e2 = 2*err;
//         if (e2 >= dy) 
//             err += dy; /* e_xy+e_x > 0 */
//             x0 += sx;
//         end if
//         if (e2 <= dx) /* e_xy+e_y < 0 */
//             err += dx;
//             y0 += sy;
//         end if
//     end while
	while (x != point_dst->x || y != point_dst->y)
	{
		mlx_data->buffer_32bit[(y * mlx_data->line_pixels) + x] = colour;
		error_y = error_x;
		if (error_y > -delta_x)
		{
			error_x -= delta_y;
			x += signal_x;
		}
		if (error_y < delta_y)
		{
			error_x += delta_x;
			y += signal_y;
		}
	}
}

static void		draw_parallel(t_wiremap *wire_map, t_mlx *mlx_data, int colour, int multiplier)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x <= (wire_map->width * multiplier) && y <= (wire_map->height * multiplier))
	{
		if (y % multiplier == 0)
		{
			while (x <= (wire_map->width * multiplier))
			{
				mlx_data->buffer_32bit[(y * mlx_data->line_pixels) + x] = colour;
				++x;
			}
			x = 0;
		}
		while (x <= (wire_map->width * multiplier))
		{
			mlx_data->buffer_32bit[(y * mlx_data->line_pixels) + x] = colour;
			x += multiplier;
		}
		if (y <= (wire_map->height * multiplier))
		{
			++y;
			x = 0;
		}
	}
}

/*
** Basic function for drawing a grid, depending on the input width and height
*/

static void		draw_isometric(t_wiremap *wire_map, t_mlx *mlx_data, int colour, int multiplier)
{
	int 			coor_x;
	int				coor_y;
	
	coor_y = 0;
	coor_x = 0;
	while (coor_x <= (wire_map->width) && coor_y <= (wire_map->height))
	{
		while (coor_x <= (wire_map->width))
		{
			wire_map->map_prj[coor_y][coor_x].x = (coor_x - coor_y) * (M_SQRT2 / 2);
			wire_map->map_prj[coor_y][coor_x].y = (sqrt(3 / 2) - ((coor_x + coor_y) * (1/(sqrt(6)))));
			++coor_x;
		}
		coor_x = 0;
		++coor_y;
	}
}

/* Some potential project types: 
** AXONOMETRIC - ISOMETRIC (SSR30?)
** DIMETRIC 1:2 
** OBLIQUE - CAVALIER
** OBLIQUE - MILITARY
** PERSPECTIVE - 1(2?) Point
*/

/* 
** mlx loop : asks OS to do thing. This function also does the event management.
** mlx hook : depending on arguement, hooks certain input.
*/ 

void 	draw_wireframe(t_wiremap *wire_map)
{
	int				colour;
	t_mlx			*mlx_data;
	int				multiplier;

	mlx_data = (t_mlx*)malloc(sizeof(t_mlx));
	initialise_minilibx(mlx_data);
	colour = 0xAA023C;
	multiplier = 50;

//	draw_parallel(wire_map, mlx_data, colour, multiplier);  Removed during testing.
	draw_isometric(wire_map, mlx_data, colour, multiplier);

	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->mlx_image, 100, 100);
	mlx_hook(mlx_data->win_ptr, 2, 0, key_press, mlx_data->mlx_ptr);
	mlx_loop(mlx_data->mlx_ptr); 
}

