/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:11:32 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/26 21:14:18 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_recor(t_hit_record *rec, double root, t_vector point)
{
	rec->t = root;
	rec->point = point;
}

t_bhaskara	calculate_cone_bhaskara(t_ray *ray,
		t_vector v_origin_vertex, t_cone cone)
{
	t_bhaskara	bhaskara;
	double		k;

	k = tan(cone.angle) * tan(cone.angle);
	bhaskara.a = vector_dot(ray->direction, ray->direction) - (1 + k)
		* pow(vector_dot(ray->direction, cone.axis), 2);
	bhaskara.b = 2 * (vector_dot(ray->direction, v_origin_vertex) - (1 + k)
			* vector_dot(ray->direction, cone.axis)
			* vector_dot(v_origin_vertex, cone.axis));
	bhaskara.c = vector_dot(v_origin_vertex, v_origin_vertex) - (1 + k)
		* pow(vector_dot(v_origin_vertex, cone.axis), 2);
	bhaskara.discr = bhaskara.b * bhaskara.b - 4 * bhaskara.a * bhaskara.c;
	return (bhaskara);
}
