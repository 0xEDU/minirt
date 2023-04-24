/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:07:06 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/18 19:49:33 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Lookat must be a fixed number, not a variable
// We need to create a function to calculate the lookat, which is the camera normal
void	parse_camera(char *line, t_camera *camera)
{
	char	**split;

	split = ft_split(line, ' ');
	camera->lookfrom = parse_vector(split[1]);
	camera->lookat = parse_vector(split[2]);
	camera->fov = ft_atof(split[3]);
	ft_free_matrix((void **)split);
}