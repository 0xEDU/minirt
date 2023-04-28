/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:13:41 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/27 22:33:25 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "vector.h"

typedef struct s_ray
{
	t_point3	origin;
	union
	{
		t_vector	direction;
		t_vector	dir;
	};
}				t_ray;

/* Light pseudo-methods */
t_point3	ray_at(t_ray ray, double t);

#endif