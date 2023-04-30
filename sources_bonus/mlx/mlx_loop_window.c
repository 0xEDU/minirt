/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:36:47 by edu               #+#    #+#             */
/*   Updated: 2023/04/30 00:43:27 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	expose_event(t_minirt *minirt)
{
	mlx_clear_window(minirt->mlx.mlx, minirt->mlx.window);
	mlx_image_to_window(minirt, 0, 0);
	return (0);
}

void	mlx_loop_window(t_minirt *minirt)
{
	mlx_key_hook(minirt->mlx.window, &mlx_key_press_events, minirt);
	mlx_hook(minirt->mlx.window, 17, 0, mlx_click_press_events, minirt);
	mlx_expose_hook(minirt->mlx.window, &expose_event, minirt);
	mlx_loop(minirt->mlx.mlx);
}
