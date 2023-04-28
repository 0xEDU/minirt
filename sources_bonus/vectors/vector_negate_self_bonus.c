/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_negate_self.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:04:41 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/22 22:25:05 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_negate_self(t_vector *vector)
{
	vector->x *= -1;
	vector->y *= -1;
	vector->z *= -1;
	return (*vector);
}
