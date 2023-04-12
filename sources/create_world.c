/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:39:52 by etachott          #+#    #+#             */
/*   Updated: 2023/04/12 15:03:08 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_world(t_hittable_list *world)
{
	t_cylinder	*cyl1;
	t_sphere	*sphere1;
	// t_sphere	*sphere2;
	// t_sphere	*sphere3;
	t_plane		*plane1;
	t_plane		*plane2;
	t_plane		*plane3;

	cyl1 = ft_calloc(sizeof(t_cylinder), 1);
	cyl1->center = vector_create(0, 0, 0);
	cyl1->radius = 2;
	cyl1->axis = vector_create(0, 1, 0);
	cyl1->height = 6;
	cyl1->cap_top = vector_sum(cyl1->center, vector_mult(cyl1->axis, cyl1->height/ 2.0));
	cyl1->cap_bottom = vector_sum(cyl1->center, vector_mult(cyl1->axis, -(cyl1->height / 2.0)));
	cyl1->type = CYLINDER;
	cyl1->m.ambient = 0.1;
	cyl1->m.diffuse = 0.7;
	cyl1->m.specular = 0.3;
	cyl1->m.shininess = 200;
	cyl1->m.color = vector_create(0.1, 1, 0.5);

	sphere1 = ft_calloc(sizeof(t_sphere), 1);
	sphere1->center = vector_create(0, 0, 0);
	sphere1->radius = 3;
	sphere1->type = SPHERE;
	sphere1->m.ambient = 0.1;
	sphere1->m.diffuse = 0.7;
	sphere1->m.specular = 0.3;
	sphere1->m.shininess = 200;
	sphere1->m.color = vector_create(0.1, 1, 0.5);

	// sphere2 = ft_calloc(sizeof(t_sphere), 1);
	// sphere2->center = vector_create(3, 0.5, -0.5);
	// sphere2->radius = 0.5;
	// sphere2->type = SPHERE;
	// sphere2->m.ambient = 0.1;
	// sphere2->m.diffuse = 0.7;
	// sphere2->m.specular = 0.3;
	// sphere2->m.shininess = 200;
	// sphere2->m.color = vector_create(0.5, 1, 0.1);

	// sphere3 = ft_calloc(sizeof(t_sphere), 1);
	// sphere3->center = vector_create(-2.5, 0.33, -0.75);
	// sphere3->radius = 0.33;
	// sphere3->type = SPHERE;
	// sphere3->m.ambient = 0.1;
	// sphere3->m.diffuse = 0.7;
	// sphere3->m.specular = 0.3;
	// sphere3->m.shininess = 200;
	// sphere3->m.color = vector_create(1, 0.8, 0.1);

	plane1 = ft_calloc(sizeof(t_plane), 1);
	plane1->normal = vector_create(0, 1, 0);
	plane1->position = vector_create(0, 0, 0);
	plane1->type = PLANE;
	plane1->m.ambient = 0.1;
	plane1->m.diffuse = 0.9;
	plane1->m.specular = 0.5;
	plane1->m.shininess = 200;
	plane1->m.color = vector_create(1, 0.9, 0.9);
	
	plane2 = ft_calloc(sizeof(t_plane), 1);
	plane2->normal = vector_create(1, 0, 0);
	plane2->position = vector_create(14, 0, 0);
	plane2->type = PLANE;
	plane2->m.ambient = 0.1;
	plane2->m.diffuse = 0.9;
	plane2->m.specular = 0.9;
	plane2->m.shininess = 200;
	plane2->m.color = vector_create(1, 0.9, 0.9);

	plane3 = ft_calloc(sizeof(t_plane), 1);
	plane3->normal = vector_create(1, 0, 0);
	plane3->position = vector_create(-20, 0, 0);
	plane3->type = PLANE;
	plane3->m.ambient = 0.1;
	plane3->m.diffuse = 0.9;
	plane3->m.specular = 0.5;
	plane3->m.shininess = 200;
	plane3->m.color = vector_create(1, 0.9, 0.9);

	world->head = NULL;
	hittable_list_add(world, sphere1, 0, SPHERE);
	hittable_list_add(world, cyl1, 1, CYLINDER);
	// hittable_list_add(world, sphere2, 1, SPHERE);
	// hittable_list_add(world, sphere3, 2, SPHERE);
	hittable_list_add(world, plane1, 3, PLANE);
	hittable_list_add(world, plane2, 4, PLANE);
	hittable_list_add(world, plane3, 5, PLANE);
}
