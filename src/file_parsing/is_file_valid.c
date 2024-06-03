/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:10:45 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 17:22:03 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"
#include "../libft/inc/libft.h"

void	is_file_valid(t_file *file)
{
	open_file(file);
	read_file(file);
	is_minimal_scene_valid(file);
	printf("miniRT: Valid file\n");
	close(file->fd);
}
