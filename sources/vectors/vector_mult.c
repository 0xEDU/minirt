/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:13:33 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/23 16:29:30 by guribeir         ###   ########.fr       */
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
