/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_length_squared.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:21:13 by etachott          #+#    #+#             */
/*   Updated: 2023/03/27 11:48:01 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vector_length_squared(const t_vector vector)
{
	return ((vector.x * vector.x)
		+ (vector.y * vector.y)
		+ (vector.z * vector.z));
}
