/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:38:13 by etachott          #+#    #+#             */
/*   Updated: 2023/04/04 16:32:06 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_root_value(t_variation t,
			t_vector delta,
			double sqrt_discr,
			double *root)
{
	if (t.min > *root || *root > t.max)
	{
		*root = (-delta.y + sqrt_discr) / delta.x;
		if (t.min > *root || *root > t.max)
			return (0);
	}
	return (1);
}

static t_vector	set_out_normal(t_hit_record *rec, t_sphere sphere)
{
	t_vector	new;

	new = vector_div(vector_diff(rec->point, sphere.center), sphere.radius);
	return (new);
}

int	hit_sphere(t_sphere sphere, t_ray *ray, t_variation t, t_hit_record *rec)
{
	t_vector	distance;
	t_point3	delta;
	t_vector	out_normal;
	double		discr;
	double		root;

	distance = vector_diff(ray->origin, sphere.center);
	delta.x = vector_length_squared(ray->direction);
	delta.y = vector_dot(distance, ray->direction);
	delta.z = vector_length_squared(distance) - sphere.radius * sphere.radius;
	discr = delta.y * delta.y - (delta.x * delta.z);
	if (discr < 0)
		return (0);
	root = (-delta.y - sqrt(discr)) / delta.x;
	if (!check_root_value(t, delta, sqrt(discr), &root))
		return (0);
	rec->t = root;
	rec->point = ray_at(*ray, rec->t);
	out_normal = set_out_normal(rec, sphere);
	set_face_normal(rec, ray, &out_normal);
	return (1);
}
