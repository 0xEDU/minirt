/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:53:11 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/10 13:21:11 by etachott         ###   ########.fr       */
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

typedef struct s_light
{
	t_point3	source;
	t_color		color;
	double		intensity;
}				t_light;

/*Emulated Vector Methods*/
t_vector		vector_add(t_vector vector, double value);
t_vector		vector_negate_self(t_vector *vector);
t_vector		vector_sum_self(t_vector *vector, t_vector *add);
t_vector		vector_sum(t_vector vector, t_vector add);
t_vector		vector_subtr(t_vector vector, double value);
t_vector		vector_mult_self(t_vector *vector, double value);
t_vector		vector_mult(t_vector vector, double value);
t_vector		vector_div_self(t_vector *vector, double value);
t_vector		vector_div(t_vector vector, double value);
t_vector		vector_diff(t_vector u, t_vector v);
t_vector		vector_create(double x, double y, double z);
double			vector_length(t_vector vector);

/*Vector Utils*/
t_vector		vector_unit(t_vector vector);
double			vector_dot(t_vector u, t_vector v);
double			vector_length_squared(const t_vector vector);
t_vector		vector_reflect(t_vector input, t_vector normal);
t_vector		vector_cross(t_vector u, t_vector v);

/* Color functions*/
unsigned long	color_create_rgb(t_color *color);
#endif