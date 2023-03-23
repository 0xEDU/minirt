/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:25:56 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/23 16:36:25 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	ray_at(t_ray ray, double t)
{
	t_point3	point3;

	point3.x = 0.0;
	point3.y = 0.0;
	point3.z = 0.0;
	point3 = vector_sum(ray.origin, vector_mult(ray.direction, t));
	return (point3);
}
