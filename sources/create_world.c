/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:39:52 by etachott          #+#    #+#             */
/*   Updated: 2023/04/07 14:42:42 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_world(t_hittable_list *world)
{
	// t_sphere	*sphere1;
	t_plane		*plane1;
	t_plane		*plane2;
	t_plane		*plane3;
	t_plane		*plane4;
	t_plane		*plane5;
	t_plane		*plane6;

	// sphere1 = ft_calloc(sizeof(t_sphere), 1);
	// sphere1->center = vector_create(0, 2, 0);
	// sphere1->radius = 1;
	// sphere1->type = SPHERE;
	// sphere1->m.ambient = 0.1;
	// sphere1->m.diffuse = 0.9;
	// sphere1->m.specular = 0.9;
	// sphere1->m.shininess = 200;
	// sphere1->m.color = vector_create(1, 0.2, 1);
	
	plane1 = ft_calloc(sizeof(t_plane), 1);
	plane1->normal = vector_create(0, 1, 0);
	plane1->position = vector_create(0, 0, 0.1);
	plane1->type = PLANE;
	plane1->m.ambient = 0.1;
	plane1->m.diffuse = 0.9;
	plane1->m.specular = 0.5;
	plane1->m.shininess = 200;
	plane1->m.color = vector_create(0.9764, 0.4705, 0.0980);
	// plane1->m.color = vector_create(1, 1, 1);
	
	
	plane2 = ft_calloc(sizeof(t_plane), 1);
	plane2->normal = vector_create(0, 1, 0);
	plane2->position = vector_create(0, 13.1, 0);
	plane2->type = PLANE;
	plane2->m.ambient = 0.1;
	plane2->m.diffuse = 0.9;
	plane2->m.specular = 0.9;
	plane2->m.shininess = 200;
	plane2->m.color = vector_create(0.4509, 0.8431, 1.0);

	plane3 = ft_calloc(sizeof(t_plane), 1);
	plane3->normal = vector_create(1, 0, 0);
	plane3->position = vector_create(14, 0, 0);
	plane3->type = PLANE;
	plane3->m.ambient = 0.1;
	plane3->m.diffuse = 0.9;
	plane3->m.specular = 0.5;
	plane3->m.shininess = 200;
	plane3->m.color = vector_create(0.0901, 0.4705, 0.7137);

	plane4 = ft_calloc(sizeof(t_plane), 1);
	plane4->normal = vector_create(1, 0, 0);
	plane4->position = vector_create(-20, 0, 0);
	plane4->type = PLANE;
	plane4->m.ambient = 0.1;
	plane4->m.diffuse = 0.9;
	plane4->m.specular = 0.5;
	plane4->m.shininess = 200;
	plane4->m.color = vector_create(0.1882, 0.0901, 0.2039);
	// plane4->m.color = vector_create(1, 1, 1);
	
	plane5 = ft_calloc(sizeof(t_plane), 1);
	plane5->normal = vector_create(0, 0, 1);
	plane5->position = vector_create(0, 0, 20);
	plane5->type = PLANE;
	plane5->m.ambient = 0.1;
	plane5->m.diffuse = 0.9;
	plane5->m.specular = 0.9;
	plane5->m.shininess = 200;
	plane5->m.color = vector_create(0.2, 0.0901, 0.2039);

	plane6 = ft_calloc(sizeof(t_plane), 1);
	plane6->normal = vector_create(0, 0, 1);
	plane6->position = vector_create(0, 0, -39);
	plane6->type = PLANE;
	plane6->m.ambient = 0.1;
	plane6->m.diffuse = 0.9;
	plane6->m.specular = 0.9;
	plane6->m.shininess = 200;
	plane6->m.color = vector_create(0.5921, 0.4823, 0.5960);

	world->head = NULL;
	// hittable_list_add(world, sphere1, 0, SPHERE);
	hittable_list_add(world, plane1, 1, PLANE);
	hittable_list_add(world, plane2, 2, PLANE);
	hittable_list_add(world, plane3, 3, PLANE);
	hittable_list_add(world, plane4, 4, PLANE);
	hittable_list_add(world, plane5, 5, PLANE);
	hittable_list_add(world, plane6, 6, PLANE);
}
