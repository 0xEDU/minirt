/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/03/21 22:03:17 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_minirt	minirt;
	int			i;
	int			j;
	t_color		color;
	t_vector	vec1;
	t_vector	vec2;
	t_ray		ray;

	ft_bzero(&color, 1);
	ft_bzero(&vec1, 1);
	ft_bzero(&vec2, 1);
	ft_bzero(&ray, 1);
	ray.origin = &vec1;
	ray.direction = &vec2;
	vec1.x = 5;
	vec1.y = 6;
	vec1.z = 7;
	vec2.x = 15;
	vec2.y = 16;
	vec2.z = 17;
	printf("X DO RAY AT = %f\n", ray_at(&ray, 2).x);
	printf("X DO RAY ORIGIN = %f\n", ray.origin->x);
	mlx_open_window(&minirt.mlx);
	mlx_create_image(&minirt);
	i = 0;
	while (i < WIDTH)
	{
		j = HEIGHT;
		while (j >= 0)
		{
			color.r = (int)(((double)i / 1920) * 255.999);
			color.g = (int)(((double)j / 1080) * 255.999);
			color.b = 63.999;
			mlx_pixel_draw(&minirt.img, i, j, color_create_rgb(&color));
			j--;
		}
		i++;
	}
	mlx_image_to_window(&minirt, 0, 0);
	printf("DONE :D\n");
	mlx_loop_window(&minirt);
	return (0);
}
