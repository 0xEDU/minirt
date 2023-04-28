/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:06:23 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/26 21:14:36 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	cc(double height, double root, t_variation t, double cone_height)
{
	return (height >= 0 && height <= cone_height
		&& root >= t.min && root <= t.max);
}

t_bhaskara	find_bhaskara_roots(t_bhaskara bhaskara)
{
	bhaskara.root[0] = (-bhaskara.b - sqrt(bhaskara.discr)) / (2 * bhaskara.a);
	bhaskara.root[1] = (-bhaskara.b + sqrt(bhaskara.discr)) / (2 * bhaskara.a);
	return (bhaskara);
}

int	cond(double height[], double root[], t_variation t, double h)
{
	return (cc(height[0], root[0], t, h) || cc(height[1], root[1], t, h));
}

void	update_cone_hit_record(t_cone cone, t_ray *ray, t_hit_record *rec)
{
	t_vector	point_on_axis;

	point_on_axis = vector_sum(cone.vertex, vector_mult(cone.axis,
				vector_dot(vector_diff(rec->point, cone.vertex), cone.axis)));
	rec->normal = vector_unit(vector_diff(rec->point, point_on_axis));
	set_face_normal(rec, ray, &rec->normal);
}

int	hit_cone(t_cone cone, t_ray *ray, t_variation t, t_hit_record *rec)
{
	t_vector	v_origin_vertex;
	double		h[2];
	t_vector	point[2];
	t_bhaskara	bha;

	v_origin_vertex = vector_diff(ray->origin, cone.vertex);
	bha = calculate_cone_bhaskara(ray, v_origin_vertex, cone);
	if (bha.discr < 0)
		return (0);
	bha = find_bhaskara_roots(bha);
	point[0] = ray_at(*ray, bha.root[0]);
	h[0] = vector_dot(cone.axis, vector_diff(point[0], cone.vertex));
	point[1] = ray_at(*ray, bha.root[1]);
	h[1] = vector_dot(cone.axis, vector_diff(point[1], cone.vertex));
	if (cond(h, bha.root, t, cone.h))
	{
		if (cc(h[0], bha.root[0], t, cone.h) && (!cc(h[1],
					bha.root[1], t, cone.h) || bha.root[0] < bha.root[1]))
			set_recor(rec, bha.root[0], point[0]);
		else
			set_recor(rec, bha.root[1], point[1]);
		update_cone_hit_record(cone, ray, rec);
		return (1);
	}
	return (0);
}
