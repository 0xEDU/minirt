/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:36:19 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/28 23:17:02 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_light(char *line, t_light *light)
{
	char	**split;

	split = ft_split(line, ' ');
	light->source = parse_vector(split[1]);
	light->intensity = ft_atof(split[2]);
	light->color = vector_create(1, 1, 1);
	ft_free_matrix((void **)split);
}
