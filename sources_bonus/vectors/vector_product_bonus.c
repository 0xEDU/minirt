/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:38:31 by etachott          #+#    #+#             */
/*   Updated: 2023/04/10 18:39:38 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_product(t_vector u, t_vector v)
{
	t_vector	new;

	new.x = u.x * v.x;
	new.y = u.y * v.y;
	new.z = u.z * v.z;
	return (new);
}
