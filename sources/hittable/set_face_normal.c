/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_face_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:30:38 by etachott          #+#    #+#             */
/*   Updated: 2023/04/04 21:10:04 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_face_normal(t_hit_record *rec, t_ray *ray, t_vector *out_normal)
{
	rec->front_face = vector_dot(ray->direction, *out_normal) < 0;
	if (rec->front_face)
		rec->normal = *out_normal;
	else
		rec->normal = vector_negate_self(out_normal);
}
