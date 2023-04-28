/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_div.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:15:37 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/22 22:21:59 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_div(t_vector vector, double value)
{
	t_vector	new;

	new.x = vector.x / value;
	new.y = vector.y / value;
	new.z = vector.z / value;
	return (new);
}
