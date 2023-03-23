/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:38:13 by etachott          #+#    #+#             */
/*   Updated: 2023/03/23 20:01:39 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_sphere(t_point3 center, t_ray ray, double radius)
{
	t_vector	distance;
	t_vector	delta;

	distance = vector_diff(ray.origin, center);
	delta.x = vector_dot(ray.direction, ray.direction);
	delta.y = 2.0 * vector_dot(distance, ray.direction);
	delta.z = vector_dot(distance, distance) - (radius * radius);
	return ((delta.y * delta.y - 4 * delta.x * delta.z) > 0);
}