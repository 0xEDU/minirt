/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:37 by etachott          #+#    #+#             */
/*   Updated: 2023/04/04 21:03:16 by etachott         ###   ########.fr       */
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
t_color	ray_color(t_ray ray, t_hittable_list *world, t_light light)
{
	t_variation		var;
	t_hit_record	rec;

	var.min = 0;
	var.max = HUGE_VAL;
	if (hittable_list_hit(world, &ray, var, &rec))
	{
		// printf("point: %f | %f | %f\n", rec.point.x, rec.point.y, rec.point.z);
		return (lighting(world->head->object->m, light, rec.point, ray.direction, rec.normal));
	}
	return (vector_create(0, 0, 0));
}
