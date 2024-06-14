/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:49:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H
# include <stdint.h>
# include "window_management_types.h"
t_vector	add_vector(t_vector *a, t_vector *b);
t_vector	sub_vector(t_vector a, t_vector b);
float		dot_product(t_vector *a, t_vector *b);
t_vector	cross_product(t_vector *a, t_vector *b);
t_vector	multiply_vector(t_vector a, float n);
#endif