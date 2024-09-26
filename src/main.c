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
#include "../inc/hooks.h"
#include "../mlx/mlx.h"
#include "../inc/rendering.h"
#include "../inc/window_management.h"
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

int	main(int argc, char **argv)
{
	t_hook			hook;
	t_scene			scene;
	t_file			file;
	t_window		window = {0};
	t_ray_tracing	raytracer = {0};

	check_argc(argc);
	is_filename_valid(argv[1]);
	init_parsing_functions(&file);
	init_file(&file, argv[1]);
	is_file_valid(&file);
	init_stack(&scene, &file);
	close(file.fd);
	init_window_struct(&scene, &window);
	init_fct_ptr_normal(raytracer.set_normal_vector);
	create_window(&window, &scene);
	iterate_through_viewport(&window, &scene, &raytracer);
	init_hooks(&hook,&window, &scene);
	mlx_loop(window.mlx);
	free_list(scene.shapes);
	return (0);
}
