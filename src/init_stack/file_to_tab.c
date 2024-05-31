/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:53:32 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 10:21:08 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/init_stack.h"
#include "../libft/inc/libft.h"
#include "../gnl/get_next_line.h"
#include <fcntl.h>
#include <errno.h>

void	file_to_tab(char *filename)
{
	char	*ret;
	char	*line;

	ret = get_next_line(filename);
	if (!ret)
	{
		printf("miniRT: %s\n", strerror(ENOMEM));
		exit(1);
	}
	while (ret)
	{
		line = ft_strtrim(ret, "\n ");
		free(ret);
		if (!line)
		{
			ft_free_tab
			printf("miniRT: %s\n", strerror(ENOMEM));
			exit(1);
		}
		ret = get_next_line(filename);
	}
	
}
