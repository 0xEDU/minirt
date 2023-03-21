/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/03/21 18:01:35 by guribeir         ###   ########.fr       */
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
	t_color	color;

	// vector.x = 1;
	// vector.y = 2;
	// vector.z = 3;
	// point3.x = 1;
	// point3.y = 2;
	// point3.z = 3;
	color.r = 1;
	color.g = 2;
	color.b = 0.25;
	
	// printf("%f, %f, %f\n", vector.x, vector.y, vector.z);
	// printf("%f, %f, %f\n", color.x, color.y, color.z);
	// printf("%f, %f, %f\n", point3.x, point3.y, point3.z);
	mlx_open_window(&minirt.mlx);
	mlx_create_image(&minirt);
	
	i = 0;
	while (i < WIDTH)
	{
		j = HEIGHT;
		while (j >= 0)
		{
			color.r = (int) (((double)i / 1920) * 255.999);
			color.g = (int) (((double)j / 1080) * 255.999);
			color.b = 63.999;
			mlx_pixel_draw(&minirt.img, i, j, create_rgb(&color));
			j--;
		}
		i++;
	}
	mlx_image_to_window(&minirt, 0, 0);
	printf("DONE :D\n");
	mlx_loop_window(&minirt.mlx);
	return (0);
}