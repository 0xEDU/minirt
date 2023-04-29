/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:26:38 by etachott          #+#    #+#             */
/*   Updated: 2023/04/29 15:44:05 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(char *ln, t_hittable_list *world, t_minirt *minirt, int *i)
{
	t_sphere	*sphere;
	char		**split;

	split = ft_split(ln, ' ');
	sphere = ft_calloc(sizeof(t_sphere), 1);
	sphere->center = parse_vector(split[1]);
	sphere->radius = ft_atof(split[2]) / 2;
	sphere->type = SPHERE;
	sphere->m.ambient = minirt->ambient.ratio;
	sphere->m.diffuse = 0.9;
	sphere->m.specular = 0;
	sphere->m.shininess = 200;
	sphere->m.color = parse_color(split[3]);
	ft_free_matrix((void **)split);
	hittable_list_add(world, sphere, *i, SPHERE);
	(*i)++;
}
