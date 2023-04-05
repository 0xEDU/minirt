/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:35:29 by etachott          #+#    #+#             */
/*   Updated: 2023/04/05 18:48:35 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_plane(t_plane plane, t_ray *ray, t_variation t, t_hit_record *rec)
{
	double	v_distance;
	double	v_origin;	

	v_distance = vector_dot(plane.normal, ray->direction);
	//printf("v_distance: %f \n", v_distance);
	//printf("light_vector: %f | %f | %f\n", light_vector.x, light_vector.y, light_vector.z);
	if (v_distance > 0)
		return (0);
	v_origin = vector_dot(vector_sum(plane.normal, normalize(plane.position)), ray->origin);
	//printf("daale\n");
	rec->t = v_origin / v_distance;
	if (rec->t < 0 || rec->t > t.max || rec->t < t.min)
		return (0);
	rec->point.x = ray->origin.x + (ray->direction.x * rec->t);
	rec->point.y = ray->origin.y + (ray->direction.y * rec->t);
	rec->point.z = ray->origin.z + (ray->direction.z * rec->t);
	rec->normal = plane.normal;
	if (v_distance > 0)
		vector_negate_self(&rec->normal);
	return (1);
}
