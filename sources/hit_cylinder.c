/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:26:45 by etachott          #+#    #+#             */
/*   Updated: 2023/04/13 17:49:41 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector vector_project_onto_plane(t_vector v, t_vector n)
{
	t_vector n_scaled;
	double dot_product;

	dot_product = vector_dot(v, n);
	n_scaled = vector_mult(n, dot_product);
	return vector_diff(v, n_scaled);
}

static int hit_caps(t_cylinder cyl, t_ray *ray, t_variation t, t_hit_record *rec) {
	const double epsilon = 1e-6;
	double t_bottom = (vector_dot(cyl.cap_bottom, cyl.axis) - vector_dot(ray->origin, cyl.axis)) / vector_dot(ray->direction, cyl.axis);
	double t_top = (vector_dot(cyl.cap_top, cyl.axis) - vector_dot(ray->origin, cyl.axis)) / vector_dot(ray->direction, cyl.axis);

	t_vector point_bottom = ray_at(*ray, t_bottom);
	t_vector point_top = ray_at(*ray, t_top);

	double bottom_radius = vector_length(vector_diff(point_bottom, cyl.cap_bottom));
	double top_radius = vector_length(vector_diff(point_top, cyl.cap_top));

	if (t_bottom >= t.min && t_bottom <= t.max && bottom_radius <= cyl.radius - epsilon) {
		rec->t = t_bottom;
		rec->point = point_bottom;
		rec->normal = cyl.axis;
		set_face_normal(rec, ray, &rec->normal);
		return 1;
	} else if (t_top >= t.min && t_top <= t.max && top_radius <= cyl.radius - epsilon) {
		rec->t = t_top;
		rec->point = point_top;
		rec->normal = cyl.axis;
		set_face_normal(rec, ray, &rec->normal);
		return 1;
	}

	return 0;
}

int hit_cylinder(t_cylinder cyl, t_ray *ray, t_variation t, t_hit_record *rec)
{
	t_vector v;
	t_vector v_origin_center;
	double discr;
	double root1, root2;
	double a, b, c;

	v_origin_center = vector_diff(ray->origin, cyl.cap_bottom);
	t_vector projected_origin_center = vector_project_onto_plane(v_origin_center, cyl.axis);
	v = vector_project_onto_plane(ray->direction, cyl.axis);

	a = vector_length_squared(v);
	b = 2 * vector_dot(projected_origin_center, v);
	c = vector_length_squared(projected_origin_center) - cyl.radius * cyl.radius;

	discr = b * b - 4 * a * c;
	if (discr < 0)
		return 0;

	root1 = (-b - sqrt(discr)) / (2 * a);
	root2 = (-b + sqrt(discr)) / (2 * a);

	t_vector point1 = ray_at(*ray, root1);
	double height1 = vector_dot(cyl.axis, vector_diff(point1, cyl.cap_bottom));

	t_vector point2 = ray_at(*ray, root2);
	double height2 = vector_dot(cyl.axis, vector_diff(point2, cyl.cap_bottom));

	int body_hit;
	if ((height1 >= 0 && height1 <= cyl.height && root1 >= t.min && root1 <= t.max) && (height2 < 0 || height2 > cyl.height || root2 < t.min || root2 > t.max || root1 < root2))
	{
		rec->t = root1;
		rec->point = point1;
		body_hit = 1;
	}
	else if ((height2 >= 0 && height2 <= cyl.height && root2 >= t.min && root2 <= t.max) && (height1 < 0 || height1 > cyl.height || root1 < t.min || root1 > t.max || root2 < root1))
	{
		rec->t = root2;
		rec->point = point2;
		body_hit = 1;
	}
	else
	{
		body_hit = 0;
	}

	t_hit_record cap_rec;
	int cap_hit = hit_caps(cyl, ray, t, &cap_rec);

	// If there's a cap_hit, compare the t values to find the closest intersection
	if (cap_hit && body_hit) {
		if (cap_rec.t < rec->t) {
			*rec = cap_rec;
		}
	} else if (cap_hit) {
		*rec = cap_rec;
	} else if (!body_hit) {
		return 0;
	}

	t_vector point_on_axis = vector_sum(cyl.cap_bottom, vector_mult(cyl.axis, vector_dot(vector_diff(rec->point, cyl.cap_bottom), cyl.axis)));
	rec->normal = vector_unit(vector_diff(rec->point, point_on_axis));
	set_face_normal(rec, ray, &rec->normal);

	return 1;
}
