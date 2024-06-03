/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_brightness_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:21:13 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:19:28 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"

bool	is_brightness_valid(char **line)
{
	float	brightness;

	if (!is_length_valid(*line, 3))
			return (1);
	brightness = ft_atof(*line);
	if (brightness < 0 || brightness > 1)
		return (false);
	return (true);
}

//bool	is_brightness_valid(char **line, void *ptr, int option)
//{
//	t_light *light;
//	float	brightness;
//
//	if (option == PARSE
//		&&!is_length_valid(*line, 3))
//		return (1);
//	brightness = ft_atof(*line);
//	if (option == PARSE && brightness < 0 || brightness > 1)
//		return (false);
//	if (option == EXTRACT)
//	{
//		light = (t_light *)ptr;
//		light->brightness = brightness;
//	}
//	return (true);
//}
