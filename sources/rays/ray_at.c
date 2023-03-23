/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:25:56 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/22 21:21:07 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	ray_at(t_ray *ray, double t)
{
	vector_mult(*ray->direction, t);
	return (vector_sum(*ray->origin, *ray->direction));
}
