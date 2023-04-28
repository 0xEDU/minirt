/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_create_rgb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:53:40 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/28 15:39:02 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned long	color_create_rgb(t_color *color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255.999 * color->r);
	g = (int)(255.999 * color->g);
	b = (int)(255.999 * color->b);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
