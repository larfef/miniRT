#include "../libft/inc/libft.h"
#include "../../inc/constant.h"
#include <stdio.h>
#include <stdint.h>

/*
	@dev:	Displays a progress bar in the terminal, reflecting the rendering progress
			based on the current row being processed. The bar is updated as the rendering
			loop progresses through each pixel row in the viewport.
	@param:	y: the current row being rendered, used to calculate the rendering progress.
	@param:	height: the total number of rows in the viewport (window height), used to
			determine the percentage of progress made.
*/

void progress_bar(int y, int height)
{
	int32_t progress;
	int32_t pos;
	char bar[BAR_WIDTH + 1];

	progress = ((y * 100) / height);
	pos = (BAR_WIDTH * progress) / 100;
	ft_memset(bar, '=', pos);
	ft_memset(bar + pos, ' ', BAR_WIDTH - pos);
	bar[BAR_WIDTH] = '\0';
	printf("\rProgress: [%s] %d%%", bar, progress);
	write(1, "\r", 1);
	if (y == height)
		write(1, "\n", 1);
}
