/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/03/21 17:03:56 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_minirt	minirt;
	int			i;
	int			j;
	// t_vector	vector;
	// t_vector	point3;
	// t_vector	color;

	// vector.x = 1;
	// vector.y = 2;
	// vector.z = 3;
	// point3.x = 1;
	// point3.y = 2;
	// point3.z = 3;
	// color.x = 1;
	// color.y = 2;
	// color.z = 3;
	
	// printf("%f, %f, %f\n", vector.x, vector.y, vector.z);
	// printf("%f, %f, %f\n", color.x, color.y, color.z);
	// printf("%f, %f, %f\n", point3.x, point3.y, point3.z);
	mlx_open_window(&minirt.mlx);
	mlx_create_image(&minirt);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mlx_pixel_draw(&minirt.img, i, j, create_rgb(255, 0, 0));
			j++;
		}
		i++;
	}
	mlx_image_to_window(&minirt, 0, 0);
	mlx_loop_window(&minirt.mlx);
	return (0);
}