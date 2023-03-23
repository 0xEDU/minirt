/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:13:41 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/22 21:48:24 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "vector.h"

typedef struct s_ray
{
	t_point3	*origin;
	t_vector	*direction;
}				t_ray;

t_point3	ray_at(t_ray *ray, double t);
t_color		ray_color(t_ray *ray);

#endif