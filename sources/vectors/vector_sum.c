/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:11:37 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/21 19:34:43 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_sum(t_vector *vector, t_vector *add)
{
	vector->x += add->x;
	vector->y += add->y;
	vector->z += add->z;
}
