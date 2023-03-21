/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_create_rgb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:53:40 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/21 20:02:04 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned long	color_create_rgb(t_color *color)
{
	int	r;
	int	g;
	int	b;

	r = color->r;
	g = color->g;
	b = color->b;
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
