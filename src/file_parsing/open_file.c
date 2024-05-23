/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:43:43 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 16:53:02 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../inc/parsing.h"

void	open_file(t_file *file)
{
	file->fd = open(file->file, O_RDONLY);
	if (file->fd < 0)
		exit(error_message(NULL, errno));
}
