/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:21:31 by etachott          #+#    #+#             */
/*   Updated: 2023/04/26 21:00:16 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cone(char *ln, t_hittable_list *lst, t_minirt *minirt, int *i)
{
	t_cone		*cone;
	char		**split;

	split = ft_split(ln, ' ');
	cone = ft_calloc(sizeof(t_cone), 1);
	cone->vertex = parse_vector(split[1]);
	cone->axis = parse_vector(split[2]);
	cone->h = ft_atof(split[3]);
	cone->angle = ft_atof(split[4]);
	cone->type = CONE;
	cone->m.ambient = minirt->ambient.ratio;
	cone->m.diffuse = 0.9;
	cone->m.specular = 0.3;
	cone->m.shininess = 200;
	cone->m.color = parse_color(split[5]);
	hittable_list_add(lst, cone, *i, CONE);
	(*i)++;
}

// cone1 = ft_calloc(sizeof(t_cone), 1);
//     cone1->vertex = vector_create(0, 2, -5);
//     cone1->axis = vector_create(0, 1, 0);
//     cone1->angle = 12;
//     //cone1->cap_bottom = vector_create(-3, 2, 1);
//     cone1->height = 6;
//     cone1->type = CONE;
//     cone1->m.ambient = 0.2;
//     cone1->m.diffuse = 0.9;
//     cone1->m.specular = 0.3;
//     cone1->m.shininess = 200;
//     cone1->m.color = vector_create(1, 0, 0);