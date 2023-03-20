/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/03/20 19:47:26 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	1. Validate input.
*	2. Load .rt file in a t_raytracer struct (?)
*	3. Generate a scene using the struct...?
*	...
*/

// TODO:
int	main(void)
{
	t_minirt	minirt;
	int			i;
	int			j;

	mlx_open_window(&minirt.mlx);
	mlx_create_image(&minirt);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < 	HEIGHT)
		{
			mlx_pixel_draw(&minirt.img, i, j, 0x0000FF);
			j++;
		}
		i++;
	}
	mlx_image_to_window(&minirt, 0, 0);
	mlx_loop_window(&minirt.mlx);
	return (0);
}
