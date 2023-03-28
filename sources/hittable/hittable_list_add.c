/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:30:40 by etachott          #+#    #+#             */
/*   Updated: 2023/03/27 20:54:22 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	hittable_list_add(t_hittable_list *list, t_sphere *object)
{
	t_hittable_node	*new;

	new = ft_calloc(sizeof(t_hittable_node), 1);
	new->object = object;
	new->next = list->head;
	list->head = new;
}
