/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 01:47:51 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/28 01:53:16 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit	init_hit(t_cylinder *cyl, t_ray *ray, t_variation t,
	t_hit_record *rec)
{
	t_hit	hit;

	hit.cyl = cyl;
	hit.ray = ray;
	hit.t = t;
	hit.rec = rec;
	return (hit);
}

t_bhaskara	init_bhaskara(t_vector pj_ori_center,
	t_vector v, double radius)
{
	t_bhaskara	bhaskara;

	bhaskara.a = vector_length_sqd(v);
	bhaskara.b = 2 * vector_dot(pj_ori_center, v);
	bhaskara.c = vector_length_sqd(pj_ori_center) - radius * radius;
	bhaskara.discr = bhaskara.b * bhaskara.b - 4 * bhaskara.a * bhaskara.c;
	return (bhaskara);
}

void	update_hit_record(t_hit_record *rec, t_vector point,
	t_vector cap_bottom, t_vector axis)
{
	rec->normal = vector_unit(vector_diff(point,
				vector_sum(cap_bottom, vector_mult(axis,
						vector_dot(vector_diff(point, cap_bottom), axis)))));
}
