/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:14 by etachott          #+#    #+#             */
/*   Updated: 2023/04/24 20:39:19 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_ambient(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 3)
		return (clean_return(0, (void **)split));
	if (!validate_ratio(split[1]))
		return (clean_return(0, (void **)split));
	if (!validate_color(split[2]))
		return (clean_return(0, (void **)split));
	return (clean_return(1, (void **)split));
}