/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:26:45 by etachott          #+#    #+#             */
/*   Updated: 2023/04/10 18:56:38 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

	// static int	check_root_value(t_variation t,
	// 			t_vector delta,
	// 			double sqrt_discr,
	// 			double *root)
	// {
	// 	if (t.min 	> *root || *root > t.max)
	// 	{
	// 		*root = -delta.y - sqrt_discr / 2 * delta.x;
	// 		if (t.min > *root || *root > t.max)
	// 			return (0);
	// 	}
	// 	return (1);
	// }

static int check_root_value(t_cylinder *cyl, t_ray *ray, double root)
{
	t_point3 point;
	t_vector relative_point;
	double projected_height;

	point = ray_at(*ray, root);
	relative_point = vector_diff(point, cyl->cap_bottom);
	projected_height = vector_dot(relative_point, cyl->axis);
	if (0 <= projected_height && projected_height <= cyl->height)
		return 1;
	return 0;
}

static t_vector vector_project_onto_plane(t_vector v, t_vector n)
{
	t_vector n_scaled;
	double dot_product;

	dot_product = vector_dot(v, n);
	n_scaled = vector_mult(n, dot_product);
	return vector_diff(v, n_scaled);
}

	// b ← 2 * ray.origin.x * ray.direction.x +
	// 2 * ray.origin.z * ray.direction.z
	//
	// c ← ray.origin.x² + ray.origin.z² - 1
	// int	hit_cylinder(t_cylinder cyl, t_ray *ray, t_variation t, t_hit_record *rec)
	// {
	// 	t_vector	delta;
	// 	double		discr;
	// 	double		root;

	// 	delta.x = ray->direction.x * ray->direction.x + ray->direction.z * ray->direction.z;
	// 	// if (0 < delta.x && delta.x < 0.0001)
	// 	// 	return (0);
	// 	delta.y = 2 * ray->origin.x * ray->origin.x + 2 * ray->origin.z * ray->origin.z;
	// 	delta.z = ray->direction.x * ray->direction.x + ray->direction.z * ray->direction.z - 1;
	// 	discr = delta.y * delta.y - 4 * delta.x * delta.z;
	// 	if (discr < 0)
	// 		return (0);
	// 	root = -delta.y + sqrt(discr) / 2 * delta.x;
	// 	if (!check_root_value(t, delta, sqrt(discr), &root))
	// 		return (0);
	// 	rec->t = root;
	// 	rec->point = ray_at(*ray, rec->t);
	// 	rec->normal = vector_diff(vector_project_onto_plane(vector_diff(rec->point, cyl.center), cyl.axis), rec->point);
	// 	set_face_normal(rec, ray, &rec->normal);
	// 	return (1);
	// }




// int hit_cylinder(t_cylinder cyl, t_ray *ray, t_variation t, t_hit_record *rec)
// {
// 	t_vector v;
// 	t_vector v_origin_center;
// 	t_vector delta;
// 	double discr;
// 	double root;

// 	v_origin_center = vector_diff(ray->origin, cyl.center);
// 	v = vector_project_onto_plane(ray->direction, cyl.axis);
// 	delta.x = vector_length_squared(v);
// 	v = vector_project_onto_plane(v_origin_center, cyl.axis);
// 	delta.y = 2 * vector_dot(v, ray->direction);
// 	delta.z = vector_length_squared(v) - cyl.radius * cyl.radius;
// 	discr = delta.y * delta.y - 4 * delta.x * delta.z;
// 	if (discr < 0)
// 		return (0);
// 	root = (-delta.y - sqrt(discr)) / (2 * delta.x);
// 	if (!check_root_value(t, &cyl, ray, root))
// 	{
// 		root = (-delta.y + sqrt(discr)) / (2 * delta.x);
// 		if (!check_root_value(t, &cyl, ray, root))
// 			return (0);
// 	}
// 	rec->t = root;
// 	rec->point = ray_at(*ray, rec->t);
// 	rec->normal = vector_unit(vector_diff(vector_project_onto_plane(vector_diff(rec->point, cyl.center), cyl.axis), rec->point));
// 	set_face_normal(rec, ray, &rec->normal);
// 	return (1);
// }

int hit_cylinder(t_cylinder cyl, t_ray *ray, t_hit_record *rec)
{
	t_vector v;
	t_vector v_origin_center;
	// t_vector delta;
	double discr;
	double root;
	double a, b, c;

	v_origin_center = vector_diff(ray->origin, cyl.center);
	t_vector projected_origin_center = vector_project_onto_plane(v_origin_center, cyl.axis);
	v = vector_project_onto_plane(ray->direction, cyl.axis);

	a = vector_length_squared(v);
	b = 2 * vector_dot(projected_origin_center, v);
	c = vector_length_squared(projected_origin_center) - cyl.radius * cyl.radius;

	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);

	root = (-b - sqrt(discr)) / (2 * a);
	if (!check_root_value(&cyl, ray, root))
	{
		root = (-b + sqrt(discr)) / (2 * a);
		if (!check_root_value(&cyl, ray, root))
			return (0);
	}
	rec->t = root;
	rec->point = ray_at(*ray, rec->t);
	t_vector point_on_axis = vector_sum(cyl.center, vector_mult(cyl.axis, vector_dot(vector_diff(rec->point, cyl.center), cyl.axis)));
	rec->normal = vector_unit(vector_diff(rec->point, point_on_axis));
	set_face_normal(rec, ray, &rec->normal);

	return (1);
}