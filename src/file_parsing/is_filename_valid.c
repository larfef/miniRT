/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_filename_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:44:42 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"
#include "../libft/inc/libft.h"

/*
	@dev:	Validates the file extension of the provided filename to ensure
			that it ends with ".rt", which is required for the ray tracing
			application. If the filename does not have the correct extension,
			an error message is printed, and the program terminates.

	@param:	filename: A constant pointer to the string representing the
			filename that needs to be validated.

	@behavior:
		1. Searches for the ".rt" file extension in the `filename` using
		   `ft_strnstr()`.
		2. Checks whether the extension is present and ensures that the length
		   of the extension is exactly 3 characters (to avoid partial matches).
		3. If the extension is not valid, prints an error message and
		   terminates the program with `exit(1)`.

	@return:	None. The function either validates the filename or terminates
				the program with an error message if the extension is invalid.
*/

void	is_filename_valid(char const *filename)
{
	char	*file_extension;

	file_extension = ft_strnstr(filename, ".rt", ft_strlen(filename));
	if (!file_extension
		|| ft_strlen(file_extension) != 3)
	{
		printf("miniRT: %s\n", E_EXT);
		exit(1);
	}
}
