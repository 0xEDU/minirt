/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:46:40 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/27 14:32:08 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ray_color(t_ray ray)
{
	t_vector		unit_direction;
	double			t;
	t_color			color1;
	t_vector		normal;
	t_sphere		sphere;
	t_variation		var;
	t_hit_record	rec;

	sphere.center = vector_create(0, 0, -1);
	sphere.radius = 0.5;
	var.min = -1;
	var.max = 100;
	t = hit_sphere(sphere, &ray, var, &rec);
	if (t)
	{
		/*normal = vector_unit(vector_diff(ray_at(ray, t),
					vector_create(0, 0, -1)));*/
		normal = rec.normal;
		return (vector_mult(
				vector_create(normal.r + 1, normal.g + 1, normal.b + 1),
				0.5 * 255.999));
		
	}
	unit_direction = vector_unit(ray.direction);
	t = 0.5 * (unit_direction.y + 1.0);
	color1.r = (unsigned char)(255.999 * (1.0 - t + t * 0.5));
	color1.g = (unsigned char)(255.999 * (1.0 - t + t * 0.7));
	color1.b = (unsigned char)(255.999 * (1.0 - t + t * 1));
	return (color1);
}
