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

#include <unistd.h>
#include "mlx.h"

int main()
{
	void *mlx_ptr; /* connection login to the graphical server */
	void *win_ptr; /* an identifier for the window (MiniLibX can open many) */
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Basic Program");
//	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
//	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr); /* asks OS to do thing. This function also does the event management. */


	
}
