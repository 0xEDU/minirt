/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:37 by etachott          #+#    #+#             */
/*   Updated: 2023/04/05 19:07:06 by etachott         ###   ########.fr       */
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
		if (index == current->index)
			material = current->plane->m;
		current = current->next;
	}
	return (material);
}

t_color	ray_color(t_ray ray, t_hittable_list *world, t_light light)
{
	t_variation		var;
	t_hit_record	rec;

	var.min = 0;
	var.max = HUGE_VAL;
	if (hittable_list_hit(world, &ray, var, &rec))
	{
		return (lighting(get_material(world, rec.index), light, rec.point, ray.direction, rec.normal));
	}
	return (vector_create(0, 0, 0));
}
