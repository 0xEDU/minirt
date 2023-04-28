/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 01:20:41 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/28 01:42:43 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calculate_t_bt(t_vector aot, t_ray ray, t_vector axis)
{
	if (fabs(vector_dot(ray.direction, axis)) < 1e-6)
		return (-1);
	return (vector_dot(aot, axis) / vector_dot(ray.direction, axis));
}

int	find_hit_result(t_hit hit, double t_bt[2], t_vector point_bt[2])
{
	int	hit_bt[2];

	hit_bt[0] = hit_caps_helper(&hit, t_bt[0], point_bt[0], 1);
	hit_bt[1] = hit_caps_helper(&hit, t_bt[1], point_bt[1], 0);
	if (hit_bt[0] && hit_bt[1])
	{
		if (t_bt[0] < t_bt[1])
			return (hit_caps_helper(&hit, t_bt[0], point_bt[0], 1));
		else
			return (hit_caps_helper(&hit, t_bt[1], point_bt[1], 0));
	}
	else if (hit_bt[0])
		return (hit_caps_helper(&hit, t_bt[0], point_bt[0], 1));
	else if (hit_bt[1])
		return (hit_caps_helper(&hit, t_bt[1], point_bt[1], 0));
	return (0);
}

// Bottom = 0
// Top = 1
// aot_bt = axis_to_origin_bt
// _bt = _bottom / _top
// I hate the norm T_T
int	hit_caps(t_cylinder c, t_ray *ray, t_variation t, t_hit_record *rec)
{
	t_hit		hit;
	double		t_bt[2];
	t_vector	point_bt[2];
	t_vector	aot_bt[2];

	hit.cyl = &c;
	hit.ray = ray;
	hit.t = t;
	hit.rec = rec;
	aot_bt[0] = vector_diff(c.cap_bottom, ray->origin);
	aot_bt[1] = vector_diff(c.cap_top, ray->origin);
	t_bt[0] = calculate_t_bt(aot_bt[0], *ray, c.axis);
	t_bt[1] = calculate_t_bt(aot_bt[1], *ray, c.axis);
	point_bt[0] = ray_at(*ray, t_bt[0]);
	point_bt[1] = ray_at(*ray, t_bt[1]);
	return (find_hit_result(hit, t_bt, point_bt));
}

int	is_valid_intersection(double h, double rt, t_hit *hit)
{
	return (h >= 0 && h <= hit->cyl->height
		&& rt >= hit->t.min && rt <= hit->t.max);
}

void	set_hit_record(t_hit *hit, double rt, t_vector point)
{
	hit->rec->t = rt;
	hit->rec->point = point;
}
