/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:44:32 by etachott          #+#    #+#             */
/*   Updated: 2023/04/24 20:49:34 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_sphere(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 4)
		return (clean_return(0, (void **)split));
	if (!validate_position(split[1]))
		return (clean_return(0, (void **)split));
	if (!validate_float(split[2]))
		return (clean_return(0, (void **)split));
	if (!validate_color(split[3]))
		return (clean_return(0, (void **)split));
	return (clean_return(1, (void **)split));
}
