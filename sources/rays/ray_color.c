/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:37 by etachott          #+#    #+#             */
/*   Updated: 2023/03/29 20:33:40 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_hittable(t_hittable *hittable, t_sphere sphere)
{
	hittable->sphere = sphere;
	hittable->type = sphere.type;
}

		// return (vector_mult(vector_sum(rec.normal,
		// 			vector_create(1, 1, 1)), 0.5));
t_color	ray_color(t_ray ray, t_hittable_list *world, t_light light, t_camera camera)
{
	t_vector		unit_direction;
	double			t;
	t_variation		var;
	t_hit_record	rec;

	var.min = 0;
	var.max = HUGE_VAL;
	if (hittable_list_hit(world, &ray, var, &rec))
		return (lighting(world->head->object->m, light, rec.point, camera, rec.normal));
	unit_direction = vector_unit(ray.direction);
	t = 0.5 * (unit_direction.y + 1.0);
	return (vector_create(0, 0, 0));
	// return (vector_sum(
	// 		vector_mult(vector_create(1.0, 1.0, 1.0), (1.0 - t)),
	// 		vector_mult(vector_create(0.5, 0.7, 1.0), t)));
}
