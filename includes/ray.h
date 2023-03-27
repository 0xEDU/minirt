/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:13:41 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/27 11:49:17 by etachott         ###   ########.fr       */
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

#endif