/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:46:40 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/22 22:32:11 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ray_color(t_ray *ray)
{
	t_vector	unit_direction;
	double		t;
	t_color		color1;

	unit_direction = vector_unit(ray->direction);
	t = 0.5 * (unit_direction.y + 1.0);
	color1.x = (unsigned char)(255.999 * (1.0 - t + t * 0.5));
	color1.y = (unsigned char)(255.999 * (1.0 - t + t * 0.7));
	color1.z = (unsigned char)(255.999 * (1.0 - t + t * 1));
	return (color1);
}
