/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:39:52 by etachott          #+#    #+#             */
/*   Updated: 2023/03/28 15:40:05 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_world(t_hittable_list *world)
{
	t_sphere	*sphere1;
	t_sphere	*sphere2;

	sphere1 = ft_calloc(sizeof(t_sphere), 1);
	sphere2 = ft_calloc(sizeof(t_sphere), 1);
	sphere1->center = vector_create(0, 0, -1);
	sphere1->radius = 0.5;
	sphere1->type = SPHERE;
	sphere1->hit = hit_sphere;
	sphere2->center = vector_create(0, -100.5, -1);
	sphere2->radius = 100;
	sphere2->type = SPHERE;
	sphere2->hit = hit_sphere;
	world->head = NULL;
	hittable_list_add(world, sphere1);
	hittable_list_add(world, sphere2);
}
