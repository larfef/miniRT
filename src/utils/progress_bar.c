/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:15:44 by rkersten          #+#    #+#             */
/*   Updated: 2024/09/27 14:15:44 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/constant.h"
#include <stdio.h>
#include <stdint.h>

/*
	@dev: Displays a progress bar in the console based on the
		  current iteration of a process.

	@params: y: The current iteration or progress value.
			  height: The total number of iterations or the
					  maximum value of progress.

	@return: None.

	@behavior:
		1. Calculate the progress percentage based on the current
		   iteration `y` and total `height`.
		2. Determine the position of the progress indicator within
		   the bar using the `BAR_WIDTH`.
		3. Fill the progress bar with '=' characters for completed
		   progress and spaces for remaining progress.
		4. Update the console output with the progress bar and
		   percentage value.
		5. If the process reaches the last iteration, move to a new line.
*/

void	progress_bar(int y, int height)
{
	int32_t	progress;
	int32_t	pos;
	char	bar[BAR_WIDTH + 1];

	progress = ((y * 100) / height);
	pos = (BAR_WIDTH * progress) / 100;
	ft_memset(bar, '=', pos);
	ft_memset(bar + pos, ' ', BAR_WIDTH - pos);
	bar[BAR_WIDTH] = '\0';
	printf("\rProgress: [%s] %d%%", bar, progress);
	write(1, "\r", 1);
}
