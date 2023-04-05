/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:39:52 by etachott          #+#    #+#             */
/*   Updated: 2023/04/05 19:12:03 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_world(t_hittable_list *world)
{
	t_sphere	*sphere1;
	t_plane		*plane1;
	// t_plane		*plane2;
	// t_plane		*plane3;

	sphere1 = ft_calloc(sizeof(t_sphere), 1);
	sphere1->center = vector_create(0, 0, 0);
	sphere1->radius = 1;
	sphere1->type = SPHERE;
	sphere1->m.ambient = 0.1;
	sphere1->m.diffuse = 0.9;
	sphere1->m.specular = 0.9;
	sphere1->m.shininess = 200;
	sphere1->m.color = vector_create(1, 0.2, 1);
	
	plane1 = ft_calloc(sizeof(t_plane), 1);
	plane1->normal = vector_create(0, 1, 0);
	plane1->position = vector_create(0, 0, 10);
	plane1->type = PLANE;
	plane1->m.ambient = 0.1;
	plane1->m.diffuse = 0.9;
	plane1->m.specular = 0.9;
	plane1->m.shininess = 200;
	plane1->m.color = vector_create(0.7, 0.1, 0.1);
	
	// plane2 = ft_calloc(sizeof(t_plane), 1);
	// plane2->normal = vector_create(1, 0, 0);
	// plane2->position = vector_create(0, 1, 10);
	// plane2->type = PLANE;
	// plane2->m.ambient = 0.1;
	// plane2->m.diffuse = 0.9;
	// plane2->m.specular = 0.9;
	// plane2->m.shininess = 200;
	// plane2->m.color = vector_create(0.0, 0, 1.0);

	// plane3 = ft_calloc(sizeof(t_plane), 1);
	// plane3->normal = vector_create(1, 0, 0);
	// plane3->position = vector_create(0, 0, 10);
	// plane3->type = PLANE;
	// plane3->m.ambient = 0.1;
	// plane3->m.diffuse = 0.9;
	// plane3->m.specular = 0.9;
	// plane3->m.shininess = 200;
	// plane3->m.color = vector_create(0.0, 0, 1.0);
	world->head = NULL;
	hittable_list_add(world, sphere1, 0);
	hittable_list_add(world, plane1, 1);
	// hittable_list_add(world, plane2, 2);
	// hittable_list_add(world, plane3, 3);
}
