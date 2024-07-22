/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:58:24 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 17:23:45 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"
#include "../inc/init_stack.h"
#include "../inc/window_management.h"
#include "../inc/hooks.h"
#include "libft/inc/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static	void	check_argc(int argc)
{
	if (argc != 2)
	{
		printf("miniRT: %s\n", E_ARG);
		exit(1);
	}
}

void	window_management()
{

}

int	main(int argc, char **argv)
{
	t_scene		scene;
	t_file		file;
	t_window	window;

	check_argc(argc);
	is_filename_valid(argv[1]);
	init_parsing_functions(&file);
	init_file(&file, argv[1]);
	is_file_valid(&file);
	init_stack(&scene, &file);
	close(file.fd);
	ft_memset(&window, 0, sizeof(window));
	display(&scene, &window);
	init_hooks(&window);
	mlx_loop(window.mlx.window);
	mlx_delete_image(window.mlx.window, window.image);
	mlx_terminate(window.mlx.window);
	free_list(scene.shapes);
	return (0);
}
