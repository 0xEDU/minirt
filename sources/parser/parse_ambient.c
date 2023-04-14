/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:27:08 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/14 16:37:19 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void parse_ambient(char *line, t_ambient *ambient)
{
	char	**split;

	split = ft_split(line, ' ');
	ambient->ratio = ft_atof(split[1]);
	ambient->color = parse_color(split[2]);
	ft_free_matrix((void **)split);
}