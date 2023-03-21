/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:05:53 by edu               #+#    #+#             */
/*   Updated: 2023/03/21 20:08:56 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_close_window(t_minirt *minirt)
{
	mlx_destroy_image(minirt->mlx.mlx, minirt->img.img);
	mlx_destroy_window(minirt->mlx.mlx, minirt->mlx.window);
	mlx_destroy_display(minirt->mlx.mlx);
	if (minirt->mlx.mlx)
		free(minirt->mlx.mlx);
	exit(0);
}
