/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:07:06 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/24 09:56:22 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_camera(char *line, t_camera *camera)
{
	char	**split;

	split = ft_split(line, ' ');
	camera->lookfrom = parse_vector(split[1]);
	camera->lookat = parse_vector(split[2]);
	camera->fov = ft_atof(split[3]);
	ft_free_matrix((void **)split);
}
