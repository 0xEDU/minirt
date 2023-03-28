/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/03/28 13:29:41 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_minirt		minirt;
	t_hittable_list	*world;

	world = ft_calloc(sizeof(t_hittable_list), 1);
	init_minirt(&minirt);
	mlx_open_window(&minirt.mlx);
	mlx_create_image(&minirt);
	create_world(world);
	render_scene(&minirt, world);
	mlx_image_to_window(&minirt, 0, 0);
	printf("DONE :D\n");
	mlx_loop_window(&minirt);
	return (0);
}
