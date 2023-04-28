/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:26:45 by etachott          #+#    #+#             */
/*   Updated: 2023/04/27 22:39:41 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	hit_caps_helper(t_hit *hit, double t_val,
	t_vector point, int is_bottom)
{
	const double	epsilon = 1e-6;
	double			radius;
	t_vector		cap;

	if (is_bottom)
		cap = hit->cyl->cap_bottom;
	else
		cap = hit->cyl->cap_top;
	radius = vector_length(vector_diff(point, cap));
	if (t_val >= hit->t.min && t_val <= hit->t.max
		&& radius <= hit->cyl->radius - epsilon)
	{
		hit->rec->t = t_val;
		hit->rec->point = point;
		if (is_bottom)
			hit->rec->normal = vector_mult(hit->cyl->axis, -1);
		else
			hit->rec->normal = hit->cyl->axis;
		set_face_normal(hit->rec, hit->ray, &hit->rec->normal);
		return (1);
	}
	return (0);
}

// Bottom = 0
// Top = 1
// aot_bt = axis_to_origin_bt
// _bt = _bottom / _top
// I hate the norm T_T
static int	hit_caps(t_cylinder c, t_ray *ray,
	t_variation t, t_hit_record *rec)
{
	double		t_bt[2];
	t_hit		hit;
	t_vector	point_bt[2];
	int			hit_bt[2];
	t_vector	aot_bt[2];

	hit.cyl = &c;
	hit.ray = ray;
	hit.t = t;
	hit.rec = rec;
	aot_bt[0] = vector_diff(c.cap_bottom, ray->origin);
	aot_bt[1] = vector_diff(c.cap_top, ray->origin);
	t_bt[0] = -1;
	if (!(fabs(vector_dot(ray->direction, c.axis)) < 1e-6))
		t_bt[0] = vector_dot(aot_bt[0], c.axis) / vector_dot(ray->dir, c.axis);
	t_bt[1] = -1;
	if (!(fabs(vector_dot(ray->dir, c.axis)) < 1e-6))
		t_bt[1] = vector_dot(aot_bt[1], c.axis) / vector_dot(ray->dir, c.axis);
	point_bt[0] = ray_at(*ray, t_bt[0]);
	point_bt[1] = ray_at(*ray, t_bt[1]);
	hit_bt[0] = hit_caps_helper(&hit, t_bt[0], point_bt[0], 1);
	hit_bt[1] = hit_caps_helper(&hit, t_bt[1], point_bt[1], 0);
	if (hit_bt[0] && hit_bt[1])
	{
		if (t_bt[0] < t_bt[1])
			return (hit_caps_helper(&hit, t_bt[0], point_bt[0], 1));
		return (hit_caps_helper(&hit, t_bt[1], point_bt[1], 0));
	}
	else if (hit_bt[0])
		return (hit_caps_helper(&hit, t_bt[0], point_bt[0], 1));
	else if (hit_bt[1])
		return (hit_caps_helper(&hit, t_bt[1], point_bt[1], 0));
	return (0);
}

static int	select_hit(double rt[2], t_hit *hit,
	int vld_inter1, int vld_inter2)
{
	t_vector	p[2];
	double		h[2];

	p[0] = ray_at(*hit->ray, rt[0]);
	h[0] = vector_dot(hit->cyl->axis, vector_diff(p[0], hit->cyl->cap_bottom));
	p[1] = ray_at(*hit->ray, rt[1]);
	h[1] = vector_dot(hit->cyl->axis, vector_diff(p[1], hit->cyl->cap_bottom));
	vld_inter1 = (h[0] >= 0 && h[0] <= hit->cyl->height
			&& rt[0] >= hit->t.min && rt[0] <= hit->t.max);
	vld_inter2 = (h[1] >= 0 && h[1] <= hit->cyl->height
			&& rt[1] >= hit->t.min && rt[1] <= hit->t.max);
	if (vld_inter1 && vld_inter2)
	{
		if (rt[0] < rt[1])
		{
			hit->rec->t = rt[0];
			hit->rec->point = p[0];
		}
		else
		{
			hit->rec->t = rt[1];
			hit->rec->point = p[1];
		}
		return (1);
	}
	else if (vld_inter1)
	{
		hit->rec->t = rt[0];
		hit->rec->point = p[0];
		return (1);
	}
	else if (vld_inter2)
	{
		hit->rec->t = rt[1];
		hit->rec->point = p[1];
		return (1);
	}
	return (0);
}

static int	body_or_cap(t_hit *hit, int body_hit)
{
	t_hit_record	cap_rec;
	int				cap_hit;

	cap_hit = hit_caps(*hit->cyl, hit->ray, hit->t, &cap_rec);
	if (cap_hit && body_hit)
	{
		if (cap_rec.t < hit->rec->t)
		{
			*hit->rec = cap_rec;
		}
	}
	else if (cap_hit)
	{
		*hit->rec = cap_rec;
	}
	else if (!body_hit)
		return (0);
	return (1);
}

int	hit_cylinder(t_cylinder *cyl, t_ray *ray, t_variation t, t_hit_record *rec)
{
	t_hit		hit;
	t_vector	v;
	t_vector	v_origin_center;
	t_vector	pj_ori_center;
	t_bhaskara	bhaskara;

	hit = (t_hit){.cyl = cyl, .ray = ray, .t = t, .rec = rec};
	v_origin_center = vector_diff(ray->origin, cyl->cap_bottom);
	pj_ori_center = vector_project_onto_plane(v_origin_center, cyl->axis);
	v = vector_project_onto_plane(ray->direction, cyl->axis);
	bhaskara.a = vector_length_sqd(v);
	bhaskara.b = 2 * vector_dot(pj_ori_center, v);
	bhaskara.c = vector_length_sqd(pj_ori_center) - cyl->radius * cyl->radius;
	bhaskara.discr = bhaskara.b * bhaskara.b - 4 * bhaskara.a * bhaskara.c;
	if (bhaskara.discr < 0)
		return (0);
	bhaskara.root[0] = (-bhaskara.b - sqrt(bhaskara.discr)) / (2 * bhaskara.a);
	bhaskara.root[1] = (-bhaskara.b + sqrt(bhaskara.discr)) / (2 * bhaskara.a);
	if (!body_or_cap(&hit, select_hit(bhaskara.root, &hit, 0, 0)))
		return (0);
	rec->normal = vector_unit(vector_diff(rec->point,
				vector_sum(cyl->cap_bottom, vector_mult(cyl->axis,
						vector_dot(vector_diff(rec->point, cyl->cap_bottom),
							cyl->axis)))));
	set_face_normal(rec, ray, &rec->normal);
	if (!body_or_cap(&hit, select_hit(bhaskara.root, &hit, 0, 0)))
		return (0);
	return (1);
}
