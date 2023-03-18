/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/03/18 19:32:31 by edu              ###   ########.fr       */
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
// - Encapsulate t_mlx mlx in t_raytracer.
int	main(void)
{
	t_mlx	mlx;

	mlx_open_window(&mlx);
	mlx_loop_window(&mlx);
	return (0);
}
