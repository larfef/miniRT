/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:58:24 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 16:52:15 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"
#include "libft/inc/libft.h"

void	is_filename_valid(char const *filename)
{
	char	*tmp;

	tmp = ft_strnstr(filename, ".rt", ft_strlen(filename));
	if (!tmp
		|| ft_strlen(tmp) != 3)
		exit(error_message("miniRT: invalid file extension: usage: <filename.rt>", 0));
}

void	is_file_valid(char const *filename)
{
	t_file	file;

	is_filename_valid(filename);
	ft_memset(&file, '\0', sizeof(file));
	file.file = filename;
	open_file(&file);
	read_file(&file);
	printf("miniRT: Valid file\n");
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit(error_message("miniRT: usage: ./miniRT <filename.rt>", 0));
	is_file_valid(argv[1]);
	return (0);
}
