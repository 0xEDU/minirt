/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:33:45 by etachott          #+#    #+#             */
/*   Updated: 2023/04/05 19:03:33 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hittable_list_hit(t_hittable_list *list, t_ray *ray,
			t_variation t, t_hit_record *rec)
{
	t_hit_record	temp_record;
	t_hittable_node	*current;
	int				hit_anything;
	double			closest_so_far;

	hit_anything = 0;
	closest_so_far = t.max;
	current = list->head;
	while (current)
	{
		if (hit_sphere(*(current->sphere), ray, t, &temp_record))
		{
			hit_anything = 1;
			closest_so_far = temp_record.t;
			t.max = closest_so_far;
			*rec = temp_record;
			rec->index = current->index;
		}
		if (hit_plane(*(current->plane), ray, t, &temp_record))
		{
			hit_anything = 1;
			closest_so_far = temp_record.t;
			t.max = closest_so_far;
			*rec = temp_record;
			rec->index = current->index;
		}
		current = current->next;
	}
	return (hit_anything);
}
