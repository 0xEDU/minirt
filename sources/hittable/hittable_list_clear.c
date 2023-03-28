/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list_clear.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:28:13 by etachott          #+#    #+#             */
/*   Updated: 2023/03/27 19:48:25 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	hittable_list_clear(t_hittable_list *list)
{
	t_hittable_node	*current;
	t_hittable_node	*next;

	current = list->head;
	next = NULL;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	list->head = NULL;
}
