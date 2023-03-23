/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:38:13 by etachott          #+#    #+#             */
/*   Updated: 2023/03/23 20:31:50 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_sphere(t_point3 center, t_ray ray, double radius)
{
	t_vector	distance;
	t_vector	delta;
	double		discriminant;

	distance = vector_diff(ray.origin, center);
	delta.x = vector_dot(ray.direction, ray.direction);
	delta.y = 2.0 * vector_dot(distance, ray.direction);
	delta.z = vector_dot(distance, distance) - (radius * radius);
	discriminant = delta.y * delta.y - 4 * delta.x * delta.z;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-delta.y - sqrt(discriminant))/(2 * delta.x));
}
