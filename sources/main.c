/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/04/14 15:56:23 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int validate_argv(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	return (1);
}

int	main(int argc, char **argv)
{
	t_minirt		minirt;
	t_hittable_list	*world;

	if (!validate_argv(argc, argv))
		return (-1);
	init_minirt(&minirt);
	mlx_open_window(&minirt.mlx);
	mlx_create_image(&minirt);
	world = create_world(argv[1], &minirt);
	// printf("AMBIENT = %f | %f %f %f", minirt.ambient.ratio, minirt.ambient.color.r, minirt.ambient.color.g, minirt.ambient.color.b);
	render_scene(&minirt, world);
	mlx_image_to_window(&minirt, 0, 0);
	printf("DONE :D\n");
	mlx_loop_window(&minirt);
	return (0);
}
