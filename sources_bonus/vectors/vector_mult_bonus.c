/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:13:33 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/27 11:47:35 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_mult(t_vector vector, double value)
{
	t_vector	new;

	new.x = vector.x * value;
	new.y = vector.y * value;
	new.z = vector.z * value;
	return (new);
}
