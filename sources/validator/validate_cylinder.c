/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:07:48 by etachott          #+#    #+#             */
/*   Updated: 2023/04/24 21:09:43 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_cylinder(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 6)
		return (clean_return(0, (void **)split));
	if (!validate_position(split[1]))
		return (clean_return(0, (void **)split));
	if (!validate_normal(split[2]))
		return (clean_return(0, (void **)split));
	if (!validate_float(split[3]))
		return (clean_return(0, (void **)split));
	if (!validate_float(split[4]))
		return (clean_return(0, (void **)split));
	if (!validate_color(split[5]))
		return (clean_return(0, (void **)split));
	return (clean_return(1, (void **)split));
}
