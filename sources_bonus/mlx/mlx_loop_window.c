/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:36:47 by edu               #+#    #+#             */
/*   Updated: 2023/03/21 20:09:46 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_loop_window(t_minirt *minirt)
{
	mlx_key_hook(minirt->mlx.window, &mlx_key_press_events, minirt);
	mlx_hook(minirt->mlx.window, 17, 0, mlx_click_press_events, minirt);
	mlx_loop(minirt->mlx.mlx);
}
