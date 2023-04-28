/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/04/28 00:42:08 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_minirt		minirt;
	t_hittable_list	*world;
	int				fd;

	if (!validate_argv(argc, argv) || !validate_file(argv[1], -1))
		return (-1);
	init_minirt(&minirt);
	mlx_open_window(&minirt.mlx);
	mlx_create_image(&minirt);
	world = ft_calloc(sizeof(t_hittable_list), 1);
	fd = open(argv[1], O_RDONLY);
	create_world(fd, &minirt, world, 0);
	close(fd);
	minirt.world = world;
	render_scene(&minirt, world);
	mlx_image_to_window(&minirt, 0, 0);
	printf("DONE :D\n");
	mlx_loop_window(&minirt);
	return (0);
}
