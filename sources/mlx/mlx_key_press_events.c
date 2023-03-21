/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_press_events.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:54:36 by edu               #+#    #+#             */
/*   Updated: 2023/03/21 20:12:02 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_key_press_events(int key_code, t_minirt *minirt)
{
	if (key_code == 65307)
		mlx_close_window(minirt);
	return (0);
}
