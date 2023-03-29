/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reflect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:29:33 by etachott          #+#    #+#             */
/*   Updated: 2023/03/29 17:35:00 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vector_reflect(t_vector input, t_vector normal)
{
	return (vector_diff(input, vector_mult(vector_mult(normal, 2.0),
				vector_dot(input, normal))));
}
