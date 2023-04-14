/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:39:52 by etachott          #+#    #+#             */
/*   Updated: 2023/04/14 16:35:42 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hittable_list	*create_world(char *file, t_minirt *minirt)
{
	t_hittable_list	*world;
	int				fd;
	char			*line;

	world = ft_calloc(sizeof(t_hittable_list), 1);
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == 'A')
			parse_ambient(line, &minirt->ambient);
		else if (line[0] == 'C')
			parse_camera(line, &minirt->camera);
		else if (line[0] == 'L')
			parse_light(line, &minirt->light);
		free(line);
	}
	close(fd);
	return (world);
}

// void	create_world(t_hittable_list *world, char **argv)
// {
// 	t_cone	*cone1;
// 	// t_cylinder	*cyl1;
// 	// t_cylinder	*cyl2;
// 	// t_cylinder	*cyl3;
// 	// t_cylinder	*cyl4;
// 	// t_cylinder	*cyl5;
	
// 	// t_sphere	*sphere1;
// 	// t_sphere	*sphere2;
// 	// t_sphere	*sphere3;
// 	// t_sphere	*sphere4;
	
// 	t_plane		*plane1;

// 	cone1 = ft_calloc(sizeof(t_cone), 1);
// 	cone1->vertex = vector_create(0, 2, -5);
// 	cone1->axis = vector_create(0, 1, 0);
// 	cone1->angle = 12;
// 	//cone1->cap_bottom = vector_create(-3, 2, 1);
// 	cone1->height = 6;
// 	cone1->type = CONE;
// 	cone1->m.ambient = 0.2;
// 	cone1->m.diffuse = 0.9;
// 	cone1->m.specular = 0.3;
// 	cone1->m.shininess = 200;
// 	cone1->m.color = vector_create(1, 0, 0);

// 	// cyl1 = ft_calloc(sizeof(t_cylinder), 1);
// 	// cyl1->center = vector_create(0, 0.5, 0);
// 	// cyl1->radius = 4;
// 	// cyl1->axis = vector_create(0, 1, 0);
// 	// cyl1->height = 9;ylinder
// 	// cyl1->cap_top = vector_sum(cyl1->center, vector_mult(cyl1->axis, cyl1->height/ 2.0));
// 	// cyl1->cap_bottom = vector_sum(cyl1->center, vector_mult(cyl1->axis, -(cyl1->height / 2.0)));
// 	// cyl1->type = CYLINDER;
// 	// cyl1->m.ambient = 0.2;
// 	// cyl1->m.diffuse = 0.9;
// 	// cyl1->m.specular = 0.3;
// 	// cyl1->m.shininess = 200;
// 	// cyl1->m.color = vector_create(1, 0, 0);

// 	// cyl2 = ft_calloc(sizeof(t_cylinder), 1);
// 	// cyl2->center = vector_create(0, 4.5, -3.5);
// 	// cyl2->radius = 1.5;
// 	// cyl2->axis = vector_create(1, 0, 0);
// 	// cyl2->height = 2;
// 	// cyl2->cap_top = vector_sum(cyl2->center, vector_mult(cyl2->axis, cyl2->height/ 2.0));
// 	// cyl2->cap_bottom = vector_sum(cyl2->center, vector_mult(cyl2->axis, -(cyl2->height / 2.0)));
// 	// cyl2->type = CYLINDER;
// 	// cyl2->m.ambient = 0.2;
// 	// cyl2->m.diffuse = 0.9;
// 	// cyl2->m.specular = 0.3;
// 	// cyl2->m.shininess = 200;
// 	// cyl2->m.color = vector_create(0.5, 0.5, 1);

// 	// cyl3 = ft_calloc(sizeof(t_cylinder), 1);
// 	// cyl3->center = vector_create(3.5, 1, 5);
// 	// cyl3->radius = 1.5;
// 	// cyl3->axis = vector_create(0, 1, 0);
// 	// cyl3->height = 9;
// 	// cyl3->cap_top = vector_sum(cyl3->center, vector_mult(cyl3->axis, cyl3->height/ 2.0));
// 	// cyl3->cap_bottom = vector_sum(cyl3->center, vector_mult(cyl3->axis, -(cyl3->height / 2.0)));
// 	// cyl3->type = CYLINDER;
// 	// cyl3->m.ambient = 0.2;
// 	// cyl3->m.diffuse = 0.9;
// 	// cyl3->m.specular = 0.3;
// 	// cyl3->m.shininess = 200;
// 	// cyl3->m.color = vector_create(1, 0, 0);

// 	// cyl4 = ft_calloc(sizeof(t_cylinder), 1);
// 	// cyl4->center = vector_create(-1.65, -5, -1);
// 	// cyl4->radius = 1.5;
// 	// cyl4->axis = vector_create(0, 1, 0);
// 	// cyl4->height = 5;
// 	// cyl4->cap_top = vector_sum(cyl4->center, vector_mult(cyl4->axis, cyl4->height/ 2.0));
// 	// cyl4->cap_bottom = vector_sum(cyl4->center, vector_mult(cyl4->axis, -(cyl4->height / 2.0)));
// 	// cyl4->type = CYLINDER;
// 	// cyl4->m.ambient = 0.2;
// 	// cyl4->m.diffuse = 0.9;
// 	// cyl4->m.specular = 0.3;
// 	// cyl4->m.shininess = 200;
// 	// cyl4->m.color = vector_create(1, 0, 0);

// 	// cyl5 = ft_calloc(sizeof(t_cylinder), 1);
// 	// cyl5->center = vector_create(2.05, -5, -1);
// 	// cyl5->radius = 1.5;
// 	// cyl5->axis = vector_create(0, 1, 0);
// 	// cyl5->height = 5;
// 	// cyl5->cap_top = vector_sum(cyl5->center, vector_mult(cyl5->axis, cyl5->height/ 2.0));
// 	// cyl5->cap_bottom = vector_sum(cyl5->center, vector_mult(cyl5->axis, -(cyl5->height / 2.0)));
// 	// cyl5->type = CYLINDER;
// 	// cyl5->m.ambient = 0.2;
// 	// cyl5->m.diffuse = 0.9;
// 	// cyl5->m.specular = 0.3;
// 	// cyl5->m.shininess = 200;
// 	// cyl5->m.color = vector_create(1, 0, 0);

// 	// sphere1 = ft_calloc(sizeof(t_sphere), 1);
// 	// sphere1->center = vector_create(0, 5, 0);
// 	// sphere1->radius = 4;
// 	// sphere1->type = SPHERE;
// 	// sphere1->m.ambient = 0.2;
// 	// sphere1->m.diffuse = 0.9;
// 	// sphere1->m.specular = 0.3;
// 	// sphere1->m.shininess = 200;
// 	// sphere1->m.color = vector_create(1, 0, 0);

// 	// sphere2 = ft_calloc(sizeof(t_sphere), 1);
// 	// sphere2->center = vector_create(-1, 4.5, -3.5);
// 	// sphere2->radius = 1.5;
// 	// sphere2->type = SPHERE;
// 	// sphere2->m.ambient = 0.2;
// 	// sphere2->m.diffuse = 0.9;
// 	// sphere2->m.specular = 0.3;
// 	// sphere2->m.shininess = 200;
// 	// sphere2->m.color = vector_create(0.5, 0.5, 1);

// 	// sphere3 = ft_calloc(sizeof(t_sphere), 1);
// 	// sphere3->center = vector_create(1, 4.5, -3.5);
// 	// sphere3->radius = 1.5;
// 	// sphere3->type = SPHERE;
// 	// sphere3->m.ambient = 0.2;
// 	// sphere3->m.diffuse = 0.9;
// 	// sphere3->m.specular = 0.3;
// 	// sphere3->m.shininess = 200;
// 	// sphere3->m.color = vector_create(0.5, 0.5, 1);

// 	// sphere4 = ft_calloc(sizeof(t_sphere), 1);
// 	// sphere4->center = vector_create(3.5, 5.5, 5);
// 	// sphere4->radius = 1.5;
// 	// sphere4->type = SPHERE;
// 	// sphere4->m.ambient = 0.2;
// 	// sphere4->m.diffuse = 0.9;
// 	// sphere4->m.specular = 0.3;
// 	// sphere4->m.shininess = 200;
// 	// sphere4->m.color = vector_create(1, 0, 0);

// 	plane1 = ft_calloc(sizeof(t_plane), 1);
// 	plane1->normal = vector_create(0, 1, 0);
// 	plane1->position = vector_create(0, -7.5, 0);
// 	plane1->type = PLANE;
// 	plane1->m.ambient = 0.2;
// 	plane1->m.diffuse = 0.9;
// 	plane1->m.specular = 0.5;
// 	plane1->m.shininess = 200;
// 	plane1->m.color = vector_create(0.4176470588, 0.4176470588, 0.4176470588);
	
// 	// plane2 = ft_calloc(sizeof(t_plane), 1);
// 	// plane2->normal = vector_create(1, 0, 0);
// 	// plane2->position = vector_create(14, 0, 0);
// 	// plane2->type = PLANE;
// 	// plane2->m.ambient = 0.2;
// 	// plane2->m.diffuse = 0.9;
// 	// plane2->m.specular = 0.9;
// 	// plane2->m.shininess = 200;
// 	// plane2->m.color = vector_create(1, 0.9, 0.9);

// 	// plane3 = ft_calloc(sizeof(t_plane), 1);
// 	// plane3->normal = vector_create(1, 0, 0);
// 	// plane3->position = vector_create(-20, 0, 0);
// 	// plane3->type = PLANE;
// 	// plane3->m.ambient = 0.2;
// 	// plane3->m.diffuse = 0.9;
// 	// plane3->m.specular = 0.5;
// 	// plane3->m.shininess = 200;
// 	// plane3->m.color = vector_create(1, 0.9, 0.9);

// 	world->head = NULL;
// 	hittable_list_add(world, cone1, 0, CONE);
// 	// hittable_list_add(world, cyl1, 0, CYLINDER);
// 	// hittable_list_add(world, cyl2, 1, CYLINDER);
// 	// hittable_list_add(world, cyl3, 2, CYLINDER);
// 	// hittable_list_add(world, cyl4, 3, CYLINDER);
// 	// hittable_list_add(world, cyl5, 4, CYLINDER);
// 	// hittable_list_add(world, sphere1, 5, SPHERE);
// 	// hittable_list_add(world, sphere2, 6, SPHERE);
// 	// hittable_list_add(world, sphere3, 7, SPHERE);
// 	// hittable_list_add(world, sphere4, 8, SPHERE);
// 	hittable_list_add(world, plane1, 9, PLANE);
// 	// hittable_list_add(world, plane2, 4, PLANE);
// 	// hittable_list_add(world, plane3, 5, PLANE);
// }
