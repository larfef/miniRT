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
#include <stdlib.h>
#include <stdio.h>

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
	t_scene	scene;
	t_file	file;

	check_argc(argc);
	is_filename_valid(argv[1]);
	init_parsing_functions(&file);
	init_file(&file, argv[1]);
	is_file_valid(&file);
	init_stack(&scene, &file);
	return (0);
}
