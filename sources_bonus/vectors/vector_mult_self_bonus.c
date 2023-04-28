/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult_self.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:13:33 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/22 20:55:37 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_mult_self(t_vector *vector, double value)
{
	vector->x *= value;
	vector->y *= value;
	vector->z *= value;
	return (*vector);
}
