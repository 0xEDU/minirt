/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:05:53 by edu               #+#    #+#             */
/*   Updated: 2023/04/25 17:18:45 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_list(t_hittable_list *list)
{
	t_hittable_node	*tmp;

	tmp = list->head;
	while (tmp)
	{
		list->head = tmp->next;
		free(tmp->object);
		free(tmp);
		tmp = list->head;
	}
	free(list);
}

void	mlx_close_window(t_minirt *minirt)
{
	mlx_destroy_image(minirt->mlx.mlx, minirt->img.img);
	mlx_destroy_window(minirt->mlx.mlx, minirt->mlx.window);
	mlx_destroy_display(minirt->mlx.mlx);
	if (minirt->mlx.mlx)
		free(minirt->mlx.mlx);
	free_list(minirt->world);
	exit(0);
}
