/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:13:33 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/21 21:51:55 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_mult(t_vector *vector, double value)
{
	vector->x *= value;
	vector->y *= value;
	vector->z *= value;
	return (*vector);
}
