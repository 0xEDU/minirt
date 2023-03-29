/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:59:51 by etachott          #+#    #+#             */
/*   Updated: 2023/03/29 20:44:43 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	normalize(t_vector vector)
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

t_color	lighting(t_material material, t_light light, t_point3 point, t_camera camera, t_vector normal_vector)
{
	t_color		effective_color;
	t_vector	light_vector;
	t_vector	reflect_vector;
	t_vector	eye_vector;
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	double		light_dot_normal;
	double		reflect_dot_eye;
	double		factor;

	effective_color = vector_mult(material.color, light.intensity);
	light_vector = normalize(vector_diff(light.source, point));
	eye_vector = normalize(vector_diff(point, camera.origin));
	ambient = vector_mult(effective_color, material.ambient);
	light_dot_normal = vector_dot(light_vector, normal_vector);
	//printf("camera: %f | %f | %f\n", camera.origin.x, camera.origin.y, camera.origin.z);
	// printf("normal_vector: %f | %f | %f\n", normal_vector.x, normal_vector.y, normal_vector.z);
	// printf("light_vector: %f | %f | %f\n", light_vector.x, light_vector.y, light_vector.z);
	if (light_dot_normal < 0)
	{
		// printf("entrou aqui\n");
		diffuse = vector_create(0, 0, 0);
		specular = vector_create(0, 0, 0);
	}
	else
	{
		// printf("light_dot_normal = %f\n", light_dot_normal);
		
		diffuse = vector_mult(effective_color, material.diffuse * light_dot_normal);
		reflect_vector = vector_reflect(vector_negate_self(&light_vector), normal_vector);
		reflect_dot_eye = vector_dot(reflect_vector, eye_vector); // camera.orign may be wrong;
		// printf("reflect_dot_eye: %f \n", reflect_dot_eye);
		// printf("reflect_vector: %f | %f | %f\n", reflect_vector.x, reflect_vector.y, reflect_vector.z);
		if (reflect_dot_eye <= 0)
		{
			specular = vector_create(0, 0, 0);
		}
		else
		{
			factor = pow(reflect_dot_eye, material.shininess);
			specular = vector_mult(light.color, light.intensity * material.specular * factor);
		}
	}
	return (vector_sum(vector_sum(specular, diffuse), ambient));
}
