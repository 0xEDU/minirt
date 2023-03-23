/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_subtr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:51:37 by etachott          #+#    #+#             */
/*   Updated: 2023/03/23 19:52:56 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vector_subtr(t_vector vector, double value)
{
	t_vector	new;

	new.x = vector.x - value;
	new.y = vector.y - value;
	new.z = vector.z - value;
	return (new);
}
