/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:52:26 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/02 17:52:26 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H
# define ELEMENT_ID "ACL"
# define WHITESPACE "\x08\x09\x0A\x0B\x0C\x20"
# define LEN_MAX 15
# define E_ELEM	"invalid file: scene must contain\
at least ambient light and camera"
# define E_ARG "usage: ./miniRT <filename.rt>"
# define E_DUP "invalid file: ambient light and camera must be unique"
# define E_EXT "invalid file extension: usage: <filename.rt>"
# define E_INVALID_LINE "invalid file: invalid line"
# define BRIGHTNESS 0
# define LIGHT_RATIO_MIN 0.0f
# define LIGHT_RATIO_MAX 1.0f
# define FOV_MIN 0
# define FOV_MAX 180
# define BAR_WIDTH 50
# define COORDINATES 1
# define LIGHT_RATIO 2
# define RGB 3
# define SKIP_FLOAT 4
# define SKIP_SPACE 5
# define EOL 6
# define ORIENTATION 7
# define MANDATORY_ELEM 3
# define IS_DIGIT 8
# define FOV 9
# define SKIP_DIGIT 10
# define SIZE 11
# define END 12
# define PARSE 10
# define DIAMETER 0
# define HEIGHT 1
# define EXTRACT 1
# ifndef IMAGE_WIDTH
#  define IMAGE_WIDTH 1600
# endif
# ifndef WIDTH_RATIO
#  define WIDTH_RATIO 16.0f
# endif
# ifndef HEIGHT_RATIO
#  define HEIGHT_RATIO 9.0f
# endif
# ifndef VIEWPORT_HEIGHT
#  define VIEWPORT_HEIGHT 1.0f
# endif
# define WIDTH 0
# define U 0
# define V 1
# define OFFSET_RATIO 1.0f
# define PI 3.14159265358979323846f
# define EPSILON 0.001f
# ifndef UNIT_VECTOR_EPSILON
#  define UNIT_VECTOR_EPSILON 1
# endif
# ifndef GRADIENT_END
#  define GRADIENT_END -0.9f
# endif
# ifndef NB_OF_RAY
#  define NB_OF_RAY 8
# endif
# ifndef GRID_SIZE
#  define GRID_SIZE 2
# endif
# ifndef MAX_RAY_DEPTH
#  define MAX_RAY_DEPTH 1000.0f
# endif
#endif