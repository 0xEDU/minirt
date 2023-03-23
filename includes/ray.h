/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:13:41 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/23 20:31:34 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "vector.h"

typedef struct s_ray
{
	t_point3	origin;
	t_vector	direction;
}				t_ray;

/* Light pseudo-methods */
t_point3	ray_at(t_ray ray, double t);
t_color		ray_color(t_ray ray);

/* Light hitting functions */
double		hit_sphere(t_point3 center, t_ray ray, double radius);

#endif