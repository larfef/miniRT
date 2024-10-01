/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:45:29 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/01 12:46:47 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_CODES_H
# define KEY_CODES_H
# ifdef __APPLE__
#  define ESCAPE 53
# elif __linux__
#  define ESCAPE 65307
# else
#  error "Unsupported platform"
# endif
#endif