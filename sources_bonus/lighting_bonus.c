/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:59:51 by etachott          #+#    #+#             */
/*   Updated: 2023/04/26 16:09:24 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	normalize(t_vector vector)
{
	t_vector	result;
	double		length;

	length = vector_length(vector);
	if (length == 0)
		return (vector);
	result.x = vector.x / length;
	result.y = vector.y / length;
	result.z = vector.z / length;
	return (result);
}

static void	normalize_result(t_color *result)
{
	if (result->x > 1)
		result->x = 1;
	if (result->y > 1)
		result->y = 1;
	if (result->z > 1)
		result->z = 1;
}

static void	zero_diffuse_and_specular(t_color *diffuse, t_color *specular)
{
	*diffuse = vector_create(0, 0, 0);
	*specular = vector_create(0, 0, 0);
}

t_color	lighting(t_material m, t_light light, t_hit *hit, int in_shadow)
{
	t_color		eff_color;
	t_vector	lightv;
	t_vector	reflect_v;
	t_color		colors[4];
	double		lg_d_norm;

	eff_color = vector_product(vector_mult(m.color,
				light.intensity), light.color);
	lightv = normalize(vector_diff(light.source, hit->rec->point));
	colors[AMBIENT] = vector_mult(eff_color, m.ambient);
	lg_d_norm = vector_dot(lightv, hit->rec->normal);
	colors[DIFFUSE] = vector_mult(eff_color, m.diffuse * lg_d_norm);
	reflect_v = vector_reflect(vector_negate_self(&lightv), hit->rec->normal);
	colors[SPECULAR] = vector_mult(light.color, m.specular
			* pow(vector_dot(reflect_v, hit->ray->direction), m.shininess));
	if (!(vector_dot(reflect_v, hit->ray->direction) > 0))
		colors[SPECULAR] = vector_create(0, 0, 0);
	if (!(lg_d_norm >= 0 && !in_shadow))
		zero_diffuse_and_specular(&colors[DIFFUSE], &colors[SPECULAR]);
	colors[RESULT] = vector_sum(vector_sum(colors[DIFFUSE],
				colors[SPECULAR]), colors[AMBIENT]);
	normalize_result(&colors[RESULT]);
	return (colors[RESULT]);
}
