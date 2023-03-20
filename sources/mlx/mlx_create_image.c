/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:24:11 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/20 19:26:04 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_create_image(t_minirt *minirt)
{
	minirt->img.img = mlx_new_image(minirt->mlx.mlx, WIDTH, HEIGHT);
	minirt->img.addr = mlx_get_data_addr(minirt->img.img,
			&minirt->img.bpp,
			&minirt->img.line_length,
			&minirt->img.endian);
}
