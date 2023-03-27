/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:37 by etachott          #+#    #+#             */
/*   Updated: 2023/03/27 18:47:52 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_hittable(t_hittable *hittable, t_sphere sphere)
{
	hittable->sphere = sphere;
	hittable->type = sphere.type;
}

t_color	ray_color(t_ray ray)
{
	t_vector		unit_direction;
	double			t;
	int				hit;
	t_color			color1;
	t_vector		normal;
	t_sphere		sphere;
	t_sphere		sphere2;
	t_variation		var;
	t_hit_record	rec;
	t_hittable		hittable[3];
	int				i;

	sphere.center = vector_create(0, 0.15, -1);
	sphere.radius = 0.5;
	sphere.type = SPHERE;
	sphere2.center = vector_create(0, -100.5, -1);
	sphere2.radius = 100;
	sphere2.type = SPHERE;
	var.min = 0;
	var.max = 10000000000000;
	set_hittable(&hittable[0], sphere);
	// printf("HITTABLE = %f\n", hittable[0].sphere.center.x);
	set_hittable(&hittable[1], sphere2);
	i = -1;
	while (++i < 2)
	{
		if (hittable[i].type == SPHERE)
		{
			// printf("HITTABLE = %f\n", hittable[i].sphere.center.x);
			hit = hit_sphere(hittable[i].sphere, &ray, var, &rec);
		}
		else
			hit = 0;
		if (hit)
		{
			normal = rec.normal;
			return (vector_mult(
					vector_create(normal.r + 1, normal.g + 1, normal.b + 1),
					0.5 * 255.999));
			
		}
	}
	unit_direction = vector_unit(ray.direction);
	t = 0.5 * (unit_direction.y + 1.0);
	color1.r = (unsigned char)(255.999 * (1.0 - t + t * 0.5));
	color1.g = (unsigned char)(255.999 * (1.0 - t + t * 0.7));
	color1.b = (unsigned char)(255.999 * (1.0 - t + t * 1));
	return (color1);
}
