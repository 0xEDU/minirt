/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_length_squared.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:21:13 by etachott          #+#    #+#             */
/*   Updated: 2023/04/27 21:24:11 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vector_length_sqd(const t_vector vector)
{
	return ((vector.x * vector.x)
		+ (vector.y * vector.y)
		+ (vector.z * vector.z));
}
