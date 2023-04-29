/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:45:42 by etachott          #+#    #+#             */
/*   Updated: 2023/04/29 15:56:42 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_ambient(t_ambient ambient, t_hittable_list *world)
{
	t_hittable_node	*tmp;

	tmp = world->head;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			tmp->sphere->m.ambient = ambient.ratio;
		if (tmp->type == CYLINDER)
			tmp->cylinder->m.ambient = ambient.ratio;
		if (tmp->type == PLANE)
			tmp->plane->m.ambient = ambient.ratio;
		tmp = tmp->next;
	}
}
