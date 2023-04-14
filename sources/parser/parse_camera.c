/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:07:06 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/14 16:37:28 by guribeir         ###   ########.fr       */
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
