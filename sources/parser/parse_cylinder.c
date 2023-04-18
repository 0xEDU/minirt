/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:27:43 by etachott          #+#    #+#             */
/*   Updated: 2023/04/18 18:41:12 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cylinder(char *line, t_hittable_list *world, t_minirt *minirt, int *i)
{
	t_cylinder	*cyl;
	char		**split;

	split = ft_split(line, ' ');
	cyl = ft_calloc(sizeof(t_cylinder), 1);
	cyl->center = parse_vector(split[1]);
	cyl->axis = parse_vector(split[2]);
	cyl->radius = ft_atof(split[3]) / 2;
	cyl->height = ft_atof(split[4]);
	cyl->type = CYLINDER;
	cyl->m.ambient = minirt->ambient.ratio;
	cyl->m.diffuse = 0.9;
	cyl->m.specular = 0.3;
	cyl->m.shininess = 200;
	cyl->m.color = parse_color(split[5]);
	cyl->cap_top = vector_sum(cyl->center, vector_mult(cyl->axis, cyl->height/ 2.0));
	cyl->cap_bottom = vector_sum(cyl->center, vector_mult(cyl->axis, -(cyl->height / 2.0)));
	hittable_list_add(world, cyl, *i, CYLINDER);
	// printf("Added cylinder %d\n", *i);
	(*i)++;
}