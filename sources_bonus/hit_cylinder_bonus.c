/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:26:45 by etachott          #+#    #+#             */
/*   Updated: 2023/04/28 01:49:38 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_caps_helper(t_hit *hit, double t_val,
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

static void	calculate_points_heights(double rt[2],
	t_hit *hit, t_vector p[2], double h[2])
{
	p[0] = ray_at(*hit->ray, rt[0]);
	h[0] = vector_dot(hit->cyl->axis, vector_diff(p[0], hit->cyl->cap_bottom));
	p[1] = ray_at(*hit->ray, rt[1]);
	h[1] = vector_dot(hit->cyl->axis, vector_diff(p[1], hit->cyl->cap_bottom));
}

static int	select_hit(double rt[2], t_hit *hit, int vld_inter1, int vld_inter2)
{
	t_vector	p[2];
	double		h[2];

	calculate_points_heights(rt, hit, p, h);
	vld_inter1 = is_valid_intersection(h[0], rt[0], hit);
	vld_inter2 = is_valid_intersection(h[1], rt[1], hit);
	if (vld_inter1 && vld_inter2)
	{
		if (rt[0] < rt[1])
			set_hit_record(hit, rt[0], p[0]);
		else
			set_hit_record(hit, rt[1], p[1]);
		return (1);
	}
	else if (vld_inter1)
	{
		set_hit_record(hit, rt[0], p[0]);
		return (1);
	}
	else if (vld_inter2)
	{
		set_hit_record(hit, rt[1], p[1]);
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

	hit = init_hit(cyl, ray, t, rec);
	v_origin_center = vector_diff(ray->origin, cyl->cap_bottom);
	pj_ori_center = vector_project_onto_plane(v_origin_center, cyl->axis);
	v = vector_project_onto_plane(ray->direction, cyl->axis);
	bhaskara = init_bhaskara(pj_ori_center, v, cyl->radius);
	if (bhaskara.discr < 0)
		return (0);
	bhaskara.root[0] = (-bhaskara.b - sqrt(bhaskara.discr)) / (2 * bhaskara.a);
	bhaskara.root[1] = (-bhaskara.b + sqrt(bhaskara.discr)) / (2 * bhaskara.a);
	if (!body_or_cap(&hit, select_hit(bhaskara.root, &hit, 0, 0)))
		return (0);
	update_hit_record(rec, rec->point, cyl->cap_bottom, cyl->axis);
	set_face_normal(rec, ray, &rec->normal);
	if (!body_or_cap(&hit, select_hit(bhaskara.root, &hit, 0, 0)))
		return (0);
	return (1);
}
