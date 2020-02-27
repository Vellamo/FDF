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
	if (!(mlx_data->mlx_image = (void *)mlx_new_image(mlx_data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT)))
		exit (-1);
	mlx_data->buffer_32bit = (int *)mlx_get_data_addr(mlx_data->mlx_image, &(mlx_data->pixel_bits), &(mlx_data->line_bytes), &(mlx_data->endian));
	mlx_data->line_bytes /= 4;

	return (mlx_data);
}

void 			draw_wireframe(t_wiremap *wire_map)
{
	int				colour;
	unsigned int	x;
	unsigned int	y;
	t_mlx			*mlx_data;

	mlx_data = (t_mlx*)malloc(sizeof(t_mlx));
	initialise_minilibx(mlx_data);
	colour = 0xAA023C;
	x = 0;
	y = 0;

	++wire_map;
	--wire_map;

	while (y >= 0 && y <= 500 && x >= 0 && x <= 500)
	{
    	mlx_data->buffer_32bit[(y * mlx_data->line_bytes) + x] = colour;
		++x;
		++y;
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->mlx_image, 0, 0);
	// mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_hook(mlx_data->win_ptr, 2, 0, key_press, mlx_data->mlx_ptr);
	mlx_loop(mlx_data->mlx_ptr); /* asks OS to do thing. This function also does the event management. */
}

