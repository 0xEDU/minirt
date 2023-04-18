/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:21:11 by etachott          #+#    #+#             */
/*   Updated: 2023/04/17 19:09:46 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(char *line, t_hittable_list *world, t_minirt *minirt, int *i)
{
	t_plane	*plane;
	char	**split;

	split = ft_split(line, ' ');
	plane = ft_calloc(sizeof(t_plane), 1);
	plane->position = parse_vector(split[1]);
	plane->normal = parse_vector(split[2]);
	plane->type = PLANE;
	plane->m.ambient = minirt->ambient.ratio;
	plane->m.diffuse = 0.9;
	plane->m.specular = 0.3;
	plane->m.shininess = 200;
	plane->m.color = parse_color(split[3]);
	ft_free_matrix((void **)split);
	hittable_list_add(world, plane, *i, PLANE);
	(*i)++;
}