/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:37 by etachott          #+#    #+#             */
/*   Updated: 2023/04/11 16:57:54 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	get_material(t_hittable_list *world, int index)
{
	t_hittable_node	*current;
	t_material		material;

	current = world->head;
	while (current)
	{
		if (index == current->index && current->type == PLANE)
			material = current->plane->m;
		else if (index == current->index && current->type == SPHERE)
			material = current->sphere->m;
		else if (index == current->index && current->type == CYLINDER)
			material = current->cylinder->m;
		current = current->next;
	}
	return (material);
}

static int	is_shadowed(t_point3 point, t_light light, t_hittable_list *world, int ignored_index)
{
	t_vector		shadow_vector;
	t_ray			shadow_ray;
	t_hit_record	temp_record;
	t_variation		var;
	double			distance;

	var.min = 0;
	var.max = HUGE_VAL;
	shadow_vector = vector_diff(light.source, point);
	distance = vector_length(shadow_vector);
	shadow_ray.origin = vector_sum(point, vector_mult(vector_unit(shadow_vector), 1e-4));
	shadow_ray.direction = normalize(shadow_vector);
	if (hittable_shadow_hit(world, &shadow_ray, var, &temp_record, ignored_index))
	{
		if (temp_record.t < distance)
			return (1);
	}
	return (0);
}

t_color	ray_color(t_ray ray, t_hittable_list *world, t_light light)
{
	t_variation		var;
	t_hit_record	rec;
	int				in_shadow;

	var.min = 0;
	var.max = HUGE_VAL;
	if (hittable_list_hit(world, &ray, var, &rec))
	{
		in_shadow = is_shadowed(rec.point, light, world, rec.index);
		// in_shadow = 0;
		return (lighting(get_material(world, rec.index), light, rec.point, vector_negate_self(&ray.direction), rec.normal, in_shadow));
		// return ((vector_mult(rec.normal, 0.5)));//, vector_create(0.5, 0.5, 0.5)));
	}
	return (vector_create(0, 0, 0));
}
