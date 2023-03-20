/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_click_press_events.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:13:15 by edu               #+#    #+#             */
/*   Updated: 2023/03/11 21:18:25 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_click_press_events(t_mlx *mlx)
{
	mlx_close_window(mlx);
	exit(0);
}