/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:21:31 by etachott          #+#    #+#             */
/*   Updated: 2023/04/26 20:44:54 by etachott         ###   ########.fr       */
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
	cone->height = ft_atof(split[3]);
	cone->angle = ft_atof(split[4]);
	cone->type = CONE;
	cone->m.ambient = minirt->ambient.ratio;
	cone->m.diffuse = 0.9;
	cone->m.specular = 0.3;
	cone->m.shininess = 200;
	cone->m.color = parse_color(split[5]);
	hittable_list_add(lst, cone, *i, CONE);
	ft_free_matrix((void **)split);
	(*i)++;
}
