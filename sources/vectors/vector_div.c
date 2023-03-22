/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_div.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:15:37 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/21 22:00:56 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_div(t_vector *vector, double value)
{
	vector->x /= value;
	vector->y /= value;
	vector->z /= value;
	return (*vector);
}
