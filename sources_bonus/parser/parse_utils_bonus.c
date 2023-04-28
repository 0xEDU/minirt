/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:37:06 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/24 09:56:50 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	parse_color(char *line)
{
	char	**split;
	t_color	color;

	split = ft_split(line, ',');
	color.r = ft_atof(split[0]) / 255;
	color.g = ft_atof(split[1]) / 255;
	color.b = ft_atof(split[2]) / 255;
	ft_free_matrix((void **)split);
	return (color);
}

t_vector	parse_vector(char *line)
{
	char		**split;
	t_vector	vector;

	split = ft_split(line, ',');
	vector.x = ft_atof(split[0]);
	vector.y = ft_atof(split[1]);
	vector.z = ft_atof(split[2]);
	ft_free_matrix((void **)split);
	return (vector);
}
