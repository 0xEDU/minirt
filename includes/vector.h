/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:53:11 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/21 20:05:34 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>

typedef struct s_vector
{
	union
	{
		struct
		{
			float	x;
			float	y;
			float	z;
		};
		struct
		{
			float	r;
			float	g;
			float	b;
		};
	};
}	t_vector;

typedef t_vector	t_point3;
typedef t_vector	t_color;

/*Emulated Vector Methods*/
void			vector_negate(t_vector *vector);
void			vector_sum(t_vector *vector, t_vector *add);
void			vector_mult(t_vector *vector, double value);
void			vector_div(t_vector *vector, double value);
double			vector_length(t_vector *vector);

/* Color functions*/
unsigned long	color_create_rgb(t_color *color);
#endif