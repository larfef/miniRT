/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:52:27 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

/*
	@dev: Validates the field of view (FOV) value extracted from a string.
			The function checks if the FOV is within the acceptable range
			(0 to 180 degrees). If the validation is successful and the
			option specifies that it is being used for a camera, the FOV
			value is stored in the corresponding field of the `scene`
			structure.

	@param:	p: A pointer to a string containing the FOV value to be
			validated. The string will be converted to an integer using
			`ft_atoi`.
	@param:	scene: A pointer to the `t_scene` structure, where the
			camera's FOV will be set if the option specifies it.
	@param:	option: An integer indicating the context in which the
			function is called (e.g., whether it's parsing or setting the
			FOV for a camera).

	@behavior:
		1. Converts the string value pointed to by `*p` to an integer
		   using `ft_atoi`.
		2. If `option` is set to `PARSE`, checks if the converted FOV
		   value is within the range of 0 to 180 degrees. If not,
		   returns `false`.
		3. If `option` is `_CAMERA`, sets the FOV of the camera in the
		   `scene` structure to the validated value.
		4. Returns `true` if the FOV value is valid, regardless of
		   whether it was used for parsing or for the camera.

	@return: Returns `true` if the FOV is valid; `false` if it is not
			 (only when `option` is `PARSE`).
*/

bool	is_fov_valid(char **p, t_scene *scene, int option)
{
	int64_t	tmp;

	(void)scene;
	(void)option;
	tmp = ft_atoi(*p);
	if (option == PARSE
		&& (tmp < FOV_MIN || tmp > FOV_MAX))
		return (false);
	if (option == _CAMERA)
		scene->camera.fov = tmp;
	return (true);
}

/*
	@dev: Checks whether the character pointed to by the string
			argument is a digit ('0' to '9'). This function is
			simple and returns `true` if the character is a digit
			and `false` otherwise. The context provided by the
			`scene` and `option` parameters is not utilized in this
			function.

	@param: p: A pointer to a string where the current character
			is checked. The character is accessed via dereferencing
			`*p`.
	@param: scene: A pointer to the `t_scene` structure. This
			parameter is not used in the function.
	@param: option: An integer indicating the context of the
			check. This parameter is also not used in the function.

	@behavior:
		1. Dereferences the pointer `*p` to get the current character.
		2. Checks if the character is between '0' and '9'.
		3. Returns `true` if the character is a digit, and `false`
		   otherwise.

	@return: Returns `true` if the character is a digit; `false`
			 otherwise.
*/

bool	is_digit(char **p, t_scene *scene, int option)
{
	(void)scene;
	(void)option;
	if (**p >= '0' && **p <= '9')
		return (true);
	return (false);
}

/*
	@dev: Sets the value of a floating-point variable by dereferencing
			the destination pointer. This function takes a float value
			and assigns it directly to the memory location pointed to
			by the destination pointer.

	@param: value: The floating-point value to be set.
	@param: destination: A pointer to the floating-point variable
			where the value will be stored. This pointer must not
			be NULL, as dereferencing a NULL pointer would lead
			to undefined behavior.

	@behavior:
		1. Dereferences the destination pointer and assigns the
		   provided value to it.

	@return: This function does not return a value.
*/

void	set_float(float value, float *destination)
{
	*destination = value;
}
