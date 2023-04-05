/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:56:15 by etachott          #+#    #+#             */
/*   Updated: 2023/04/04 18:57:29 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vector_add(t_vector vector, double value)
{
	t_vector	new;

	new.x = vector.x + value;
	new.y = vector.y + value;
	new.z = vector.z + value;
	return (new);
}
