/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_diff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:45:47 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/22 22:22:05 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_diff(t_vector u, t_vector v)
{
	t_vector	new;

	new.x = u.x - v.x;
	new.y = u.y - v.y;
	new.z = u.z - v.z;
	return (new);
}
