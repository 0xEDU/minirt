/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:25:56 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/04 20:51:17 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	ray_at(t_ray ray, double t)
{
	t_point3	point3;

	point3 = vector_sum(ray.origin, vector_mult(ray.direction, t));
	return (point3);
}
