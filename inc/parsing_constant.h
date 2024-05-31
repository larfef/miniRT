/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_constant.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:12:45 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 16:46:32 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_CONSTANT
# define PARSING_CONSTANT
# define LEN_MAX 15
# define E_ELEM	"invalid file: scene must contain\
 at least ambient light and camera"
# define E_ARG "usage: ./miniRT <filename.rt>"
# define E_DUP "invalid file: ambient light and camera must be unique"
# define E_EXT "invalid file extension: usage: <filename.rt>"
# define E_INVALID_LINE "invalid file: invalid line"
# define BRIGHTNESS 0
# define COORDINATES 1
# define LIGHT_RATIO 2
# define RGB 3
# define SKIP_FLOAT 4
# define SKIP_SPACE 5
# define EOL 6
# define ORIENTATION 7
# define IS_DIGIT 8
# define FOV 9
# define SKIP_DIGIT 10
# define END 11
#endif