/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:17:08 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/23 16:51:37 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vector_length(t_vector vector)
{
	double	length;

	length = (vector.x * vector.x)
		+ (vector.y * vector.y)
		+ (vector.z * vector.z);
	return (sqrt(length));
}
