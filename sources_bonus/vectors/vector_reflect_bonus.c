/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reflect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:29:33 by etachott          #+#    #+#             */
/*   Updated: 2023/04/24 10:00:02 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_vector	vector_reflect(t_vector input, t_vector normal)
// {
// 	return (vector_diff(input, vector_mult(vector_mult(normal, 2.0),
// 				vector_dot(input, normal))));
// }

t_vector	vector_reflect(t_vector v, t_vector n)
{
	t_vector		result;
	const double	dot_product = 2 * (v.x * n.x + v.y * n.y + v.z * n.z);

	result.x = v.x - dot_product * n.x;
	result.y = v.y - dot_product * n.y;
	result.z = v.z - dot_product * n.z;
	return (result);
}
