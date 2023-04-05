/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:30:40 by etachott          #+#    #+#             */
/*   Updated: 2023/04/05 19:01:30 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	hittable_list_add(t_hittable_list *list, void *object, int index)
{
	t_hittable_node	*new;

	new = ft_calloc(sizeof(t_hittable_node), 1);
	new->object = object;
	new->next = list->head;
	new->index = index;
	list->head = new;
}
