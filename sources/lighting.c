/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:59:51 by etachott          #+#    #+#             */
/*   Updated: 2023/04/25 21:42:14 by etachott         ###   ########.fr       */
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

t_color	lighting(t_material material, t_light light, t_point3 point, t_vector eyev, t_vector normal_vector, int in_shadow)
{
	t_color		effective_color;
	t_vector	light_vector;
	t_vector	reflect_vector;
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_color		result;
	double		light_dot_normal;
	double		reflect_dot_eye;
	double		factor;

	effective_color = vector_product(vector_mult(material.color, light.intensity), light.color);
	light_vector = normalize(vector_diff(light.source, point));
	ambient = vector_mult(effective_color, material.ambient);
	light_dot_normal = vector_dot(light_vector, normal_vector);
	if (light_dot_normal < 0 || in_shadow)
	{
		// printf("entrou aqui\n");
		diffuse = vector_create(0, 0, 0);
		specular = vector_create(0, 0, 0);
	}
	else
	{
		diffuse = vector_mult(effective_color, material.diffuse * light_dot_normal);
		reflect_vector = vector_reflect(vector_negate_self(&light_vector), normal_vector);
		reflect_dot_eye = vector_dot(reflect_vector, eyev); // camera.orign may be wrong;
		if (reflect_dot_eye <= 0)
		{
			specular = vector_create(0, 0, 0);
		}
		else
		{
			factor = pow(reflect_dot_eye, material.shininess);
			specular = vector_mult(light.color, material.specular * factor);
		}
	}
	result = vector_sum(vector_sum(diffuse, specular), ambient);
	if (result.x > 1)
		result.x = 1;
	if (result.y > 1)
		result.y = 1;
	if (result.z > 1)
		result.z = 1;
	return (result);
}
