/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:27:08 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/24 09:53:21 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient(char *line, t_ambient *ambient)
{
	char	**split;

	split = ft_split(line, ' ');
	ambient->ratio = ft_atof(split[1]);
	ambient->color = parse_color(split[2]);
	ft_free_matrix((void **)split);
}
