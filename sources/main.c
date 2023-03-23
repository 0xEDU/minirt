/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/03/22 21:15:44 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_minirt	minirt;

	init_minirt(&minirt);
	mlx_open_window(&minirt.mlx);
	mlx_create_image(&minirt);
	render_scene(&minirt);
	mlx_image_to_window(&minirt, 0, 0);
	printf("DONE :D\n");
	mlx_loop_window(&minirt);
	return (0);
}
