/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/04/19 21:13:40 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_minirt		minirt;
	t_hittable_list	*world;

	if (!validate_argv(argc, argv) || !validate_file(argv[1]))
		return (-1);
	printf("Passou da validaçao\n");
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
