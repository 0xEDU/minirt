/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:59:01 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/22 22:21:45 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_sum(t_vector vector, t_vector add)
{
	t_vector	new;

	new.x = vector.x + add.x;
	new.y = vector.y + add.y;
	new.z = vector.z + add.z;
	return (new);
}
