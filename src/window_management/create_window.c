/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:19:22 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 14:05:01 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/window_management.h"

static	void	test_draw(t_window *window)
{
	uint32_t	color;
	int	x;
	int	y;

	x = -1;
	y = -1;
	color = 0;
	while (++y != window->mlx.height)
	{
		while (++x != window->mlx.width)
		{
			uint8_t red = (x * 255) / (window->mlx.width - 1);
			uint8_t green = (y * 255) / (window->mlx.height - 1);;  // You can set green based on your requirements
			uint8_t blue = 0;   // You can set blue based on your requirements

			color = (red << 24) | (green << 16) | (blue << 8) | 255;
			mlx_put_pixel(window->image, x, y, color);
		}
		x = -1;
	}
}

void	create_window(t_window *window)
{
	window->mlx.height = (int32_t)window->mlx.width / window->aspect_ratio;
	if (window->mlx.height < 1)
		window->mlx.height = 1;
	window->mlx.window = mlx_init(window->mlx.width,
								   window->mlx.height, "miniRT", false);
	window->image = mlx_new_image(window->mlx.window, window->mlx.width, window->mlx.height);
	test_draw(window);
	mlx_image_to_window(window->mlx.window, window->image, 0, 0);
}
