/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:30:40 by etachott          #+#    #+#             */
/*   Updated: 2023/04/24 09:46:03 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	hittable_list_add(t_hittable_list *list, void *obj, int index, int type)
{
	t_hittable_node	*new;

	new = ft_calloc(sizeof(t_hittable_node), 1);
	new->type = type;
	new->object = obj;
	new->next = list->head;
	new->index = index;
	list->head = new;
}
