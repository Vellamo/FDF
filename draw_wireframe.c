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

static int	key_press(int keycode)
{
	ft_putnbr(keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

void draw_wireframe()
{
	void			*mlx_ptr; /* connection login to the graphical server */
	void			*win_ptr; /* an identifier for the window (MiniLibX can open many) */
	void			*image;
	int				pixel_bits;
	int				line_bytes;
	int				endian;
	int				*buffer_32bit;
	int				colour;
	unsigned int	x;
	unsigned int	y;

	if(!(mlx_ptr = mlx_init())) //Handling for init returning NULL
		return (0);
	win_ptr = (void *)mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Basic Program");
	image = (void *)mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	colour = 0x66023C;
	x = 0;
	y = 0;

	buffer_32bit = (int *)mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	line_bytes /= 4;
	
	while (y >= 0 && y <= 250 && x >= 0 && x <= 250)
	{
    	buffer_32bit[(y * line_bytes) + x] = colour;
		++x;
		++y;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, image, 0, 0);
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	// mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_hook(win_ptr, 2, 0, key_press, mlx_ptr);
	mlx_loop(mlx_ptr); /* asks OS to do thing. This function also does the event management. */

}

