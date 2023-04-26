/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:26:45 by etachott          #+#    #+#             */
/*   Updated: 2023/04/25 22:33:49 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	vector_project_onto_plane(t_vector v, t_vector n)
{
	t_vector	n_scaled;
	double		dot_product;

	dot_product = vector_dot(v, n);
	n_scaled = vector_mult(n, dot_product);
	return (vector_diff(v, n_scaled));
}

static int hit_caps(t_cylinder cyl, t_ray *ray, t_variation t, t_hit_record *rec)
{
	const double epsilon = 1e-6;
	double t_bottom = (vector_dot(cyl.cap_bottom, cyl.axis) - vector_dot(ray->origin, cyl.axis)) / vector_dot(ray->direction, cyl.axis);
	double t_top = (vector_dot(cyl.cap_top, cyl.axis) - vector_dot(ray->origin, cyl.axis)) / vector_dot(ray->direction, cyl.axis);
	t_vector point_bottom = ray_at(*ray, t_bottom);
	t_vector point_top = ray_at(*ray, t_top);
	double bottom_radius = vector_length(vector_diff(point_bottom, cyl.cap_bottom));
	double top_radius = vector_length(vector_diff(point_top, cyl.cap_top));
	if (t_bottom >= t.min && t_bottom <= t.max && bottom_radius <= cyl.radius - epsilon)
	{
		rec->t = t_bottom;
		rec->point = point_bottom;
		rec->normal = vector_mult(cyl.axis, -1);
		set_face_normal(rec, ray, &rec->normal);
		return (1);
	} 
	else if (t_top >= t.min && t_top <= t.max && top_radius <= cyl.radius - epsilon)
	{
		rec->t = t_top;
		rec->point = point_top;
		rec->normal = cyl.axis;
		set_face_normal(rec, ray, &rec->normal);
		return (1);
	}
	return (0);
}

static int	select_hit(double rt[2], t_hit *hit)
{
	t_vector	p[2];
	double		h[2];

	p[0] = ray_at(*hit->ray, rt[0]);
	h[0] = vector_dot(hit->cyl->axis, vector_diff(p[0], hit->cyl->cap_bottom));
	p[1] = ray_at(*hit->ray, rt[1]);
	h[1] = vector_dot(hit->cyl->axis, vector_diff(p[1], hit->cyl->cap_bottom));
	if ((h[0] >= 0 && h[0] <= hit->cyl->height && rt[0] >= hit->t.min
			&& rt[0] <= hit->t.max) && (h[1] < 0 || h[1] > hit->cyl->height
			|| rt[1] < hit->t.min || rt[1] > hit->t.max || rt[0] < rt[1]))
	{
		hit->rec->t = rt[0];
		hit->rec->point = p[0];
		return (1);
	}
	else if ((h[1] >= 0 && h[1] <= hit->cyl->height && rt[1] >= hit->t.min
			&& rt[1] <= hit->t.max) && (h[0] < 0 || h[0] > hit->cyl->height
			|| rt[0] < hit->t.min || rt[0] > hit->t.max || rt[1] < rt[0]))
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
			*hit->rec = cap_rec;
	}
	else if (cap_hit)
		*hit->rec = cap_rec;
	else if (!body_hit)
		return (0);
	return (1);
}

int	hit_cylinder(t_cylinder cyl, t_ray *ray, t_variation t, t_hit_record *rec)
{
	t_hit		hit;
	t_vector	v;
	t_vector	v_origin_center;
	t_vector	pj_ori_center;
	t_bhaskara	bhaskara;

	hit = (t_hit){.cyl = &cyl, .ray = ray, .t = t, .rec = rec};
	v_origin_center = vector_diff(ray->origin, cyl.cap_bottom);
	pj_ori_center = vector_project_onto_plane(v_origin_center, cyl.axis);
	v = vector_project_onto_plane(ray->direction, cyl.axis);
	bhaskara.a = vector_length_squared(v);
	bhaskara.b = 2 * vector_dot(pj_ori_center, v);
	bhaskara.c = vector_length_squared(pj_ori_center) - cyl.radius * cyl.radius;
	bhaskara.discr = bhaskara.b * bhaskara.b - 4 * bhaskara.a * bhaskara.c;
	if (bhaskara.discr < 0)
		return (0);
	bhaskara.root[0] = (-bhaskara.b - sqrt(bhaskara.discr)) / (2 * bhaskara.a);
	bhaskara.root[1] = (-bhaskara.b + sqrt(bhaskara.discr)) / (2 * bhaskara.a);
	if (!body_or_cap(&hit, select_hit(bhaskara.root, &hit)))
		return (0);
	rec->normal = vector_unit(vector_diff(rec->point, vector_sum(cyl.cap_bottom,
					vector_mult(cyl.axis, vector_dot(vector_diff(rec->point,
								cyl.cap_bottom), cyl.axis)))));
	set_face_normal(rec, ray, &rec->normal);
	return (1);
}
