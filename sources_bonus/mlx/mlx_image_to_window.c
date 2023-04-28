/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_to_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:25:49 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/20 19:26:22 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_image_to_window(t_minirt *minirt, int x, int y)
{
	mlx_put_image_to_window(
		minirt->mlx.mlx,
		minirt->mlx.window,
		minirt->img.img,
		x, y);
}
