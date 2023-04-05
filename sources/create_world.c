/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:39:52 by etachott          #+#    #+#             */
/*   Updated: 2023/04/04 20:04:27 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_world(t_hittable_list *world)
{
	t_sphere	*sphere1;

	sphere1 = ft_calloc(sizeof(t_sphere), 1);
	sphere1->center = vector_create(0, 0, 0);
	sphere1->radius = 1;
	sphere1->type = SPHERE;
	sphere1->m.ambient = 0.1;
	sphere1->m.diffuse = 0.9;
	sphere1->m.specular = 0.9;
	sphere1->m.shininess = 200;
	sphere1->m.color = vector_create(1, 0.2, 1);
	world->head = NULL;
	hittable_list_add(world, sphere1);
}
