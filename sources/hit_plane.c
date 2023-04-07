/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:35:29 by etachott          #+#    #+#             */
/*   Updated: 2023/04/07 14:46:56 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_plane(t_plane plane, t_ray *ray, t_variation t, t_hit_record *rec)
{
	double	v_distance;
	double	v_origin;
	double	temp;

	v_distance = vector_dot(plane.normal, ray->direction);
	if (fabs(v_distance) < 1e-8)
		return (0);
	v_origin = -(vector_dot(plane.normal, ray->origin) - vector_dot(plane.normal, plane.position));
	temp = v_origin / v_distance;
	if (temp > t.max || temp < t.min)
		return (0);
	rec->t = temp;
	rec->point = ray_at(*ray, rec->t);
	rec->normal = plane.normal;
	if (vector_dot(plane.normal, ray->direction) > 1e-8)
		vector_negate_self(&rec->normal);
	return (1);
}
