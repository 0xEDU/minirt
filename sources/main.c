/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/04/25 14:16:20 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_minirt		minirt;
	t_hittable_list	*world;

	if (!validate_argv(argc, argv) || !validate_file(argv[1]))
		return (-1);
	init_minirt(&minirt);
	mlx_open_window(&minirt.mlx);
	mlx_create_image(&minirt);
	world = create_world(argv[1], &minirt);
	minirt.world = world;
	render_scene(&minirt, world);
	mlx_image_to_window(&minirt, 0, 0);
	printf("DONE :D\n");
	mlx_loop_window(&minirt);
	return (0);
}
