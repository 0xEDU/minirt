/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:37 by etachott          #+#    #+#             */
/*   Updated: 2023/04/26 21:19:53 by etachott         ###   ########.fr       */
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
		else if (index == current->index && current->type == CONE)
			material = current->cone->m;
		current = current->next;
	}
	return (material);
}

static int	is_shadowed(t_point3 point, t_light light,
				t_hittable_list *world, int ignored_index)
{
	t_vector		shadow_vector;
	t_ray			shadow_ray;
	t_hit_record	temp_record;
	t_variation		var;
	t_hit			hit;

	var.min = 0;
	var.max = HUGE_VAL;
	shadow_vector = vector_diff(light.source, point);
	shadow_ray.origin = vector_sum(point,
			vector_mult(vector_unit(shadow_vector), 1e-4));
	shadow_ray.direction = normalize(shadow_vector);
	temp_record.ignore_index = ignored_index;
	hit.rec = &temp_record;
	hit.ray = &shadow_ray;
	if (hittable_shadow_hit(world, var,
			&hit, ignored_index))
	{
		if (temp_record.t < vector_length(shadow_vector))
			return (1);
	}
	return (0);
}

t_color	ray_color(t_ray ray, t_hittable_list *world, t_light light)
{
	t_hit			hit;
	int				in_shadow;

	hit.t.min = 0;
	hit.t.max = HUGE_VAL;
	hit.ray = &ray;
	hit.rec = &(t_hit_record){0};
	if (hittable_list_hit(world, hit.ray, hit.t, hit.rec))
	{
		in_shadow = is_shadowed(hit.rec->point, light, world, hit.rec->index);
		vector_negate_self(&hit.ray->direction);
		return (lighting(get_material(world, hit.rec->index), light,
				&hit, in_shadow));
	}
	return (vector_create(0, 0, 0));
}
