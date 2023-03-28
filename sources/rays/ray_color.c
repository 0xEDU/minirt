/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:37 by etachott          #+#    #+#             */
/*   Updated: 2023/03/27 20:47:56 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_hittable(t_hittable *hittable, t_sphere sphere)
{
	hittable->sphere = sphere;
	hittable->type = sphere.type;
}

t_color	ray_color(t_ray ray, t_hittable_list *world)
{
	t_vector		unit_direction;
	double			t;
	t_color			color;
	t_variation		var;
	t_hit_record	rec;

	var.min = 0;
	var.max = HUGE_VAL;
	if (hittable_list_hit(world, &ray, var, &rec))
	{
		return (vector_mult(
				vector_sum(rec.normal, vector_create(1, 1, 1)), 0.5));
	}
	unit_direction = vector_unit(ray.direction);
	t = 0.5 * (unit_direction.y + 1.0);
	color.r = (unsigned char)(255.999 * (1.0 - t + t * 0.5));
	color.g = (unsigned char)(255.999 * (1.0 - t + t * 0.7));
	color.b = (unsigned char)(255.999 * (1.0 - t + t * 1));
	return (color);
}
