/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:33:45 by etachott          #+#    #+#             */
/*   Updated: 2023/04/07 17:07:08 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hittable_shadow_hit(t_hittable_list *list, t_ray *ray,
			t_variation t, t_hit_record *rec, int ignore_index)
{
	t_hit_record	temp_record;
	t_hittable_node	*current;
	int				hit_anything;
	double			closest_so_far;
	t_variation		temp_var;

	hit_anything = 0;
	closest_so_far = t.max;
	current = list->head;
	while (current)
	{
		if (current->index != ignore_index)
		{
			temp_var.min = t.min;
			temp_var.max = closest_so_far;
			// printf("CURRENT = %d\n", current->index);
			if (current->type == SPHERE )
			{
				if (hit_sphere(*(current->sphere), ray, temp_var, &temp_record))
				{
					hit_anything = 1;
					closest_so_far = temp_record.t;
					// t.max = closest_so_far;
					*rec = temp_record;
					rec->index = current->index;
				}
			}
			else if (current->type == PLANE)
			{
				if (hit_plane(*(current->plane), ray, temp_var, &temp_record))
				{
					hit_anything = 1;
					closest_so_far = temp_record.t;
					// t.max = closest_so_far;
					*rec = temp_record;
					rec->index = current->index;
				}
			}
		}
		current = current->next;
	}
	return (hit_anything);
}

int	hittable_list_hit(t_hittable_list *list, t_ray *ray,
			t_variation t, t_hit_record *rec)
{
	t_hit_record	temp_record;
	t_hittable_node	*current;
	int				hit_anything;
	double			closest_so_far;
	t_variation		temp_var;

	hit_anything = 0;
	closest_so_far = t.max;
	current = list->head;
	while (current)
	{
		temp_var.min = t.min;
		temp_var.max = closest_so_far;
		// printf("CURRENT = %d\n", current->index);
		if (current->type == SPHERE)
		{
			if (hit_sphere(*(current->sphere), ray, temp_var, &temp_record))
			{
				hit_anything = 1;
				closest_so_far = temp_record.t;
				// t.max = closest_so_far;
				*rec = temp_record;
				rec->index = current->index;
			}
		}
		else if (current->type == PLANE)
		{
			if (hit_plane(*(current->plane), ray, temp_var, &temp_record))
			{
				hit_anything = 1;
				closest_so_far = temp_record.t;
				// t.max = closest_so_far;
				*rec = temp_record;
				rec->index = current->index;
			}
		}
		current = current->next;
	}
	return (hit_anything);
}
