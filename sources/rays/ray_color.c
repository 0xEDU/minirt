/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:37 by etachott          #+#    #+#             */
/*   Updated: 2023/03/28 15:39:34 by etachott         ###   ########.fr       */
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
		return (vector_mult(vector_sum(rec.normal,
					vector_create(1, 1, 1)), 0.5));
	unit_direction = vector_unit(ray.direction);
	t = 0.5 * (unit_direction.y + 1.0);
	return (vector_sum(
			vector_mult(vector_create(1.0, 1.0, 1.0), (1.0 - t)),
			vector_mult(vector_create(0.5, 0.7, 1.0), t)));
}
