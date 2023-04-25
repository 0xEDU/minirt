/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:22:59 by etachott          #+#    #+#             */
/*   Updated: 2023/04/25 16:44:18 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_light_values(char **split)
{
	if (!validate_position(split[1]))
	{
		printf("Error\nLight position must be in format 0,0,0\n");
		return (0);
	}
	if (!validate_ratio(split[2]))
	{
		printf("Error\nLight ratio must be between 0 and 1\n");
		return (0);
	}
	if (!validate_color(split[3]))
	{
		printf("Error\nLight color must be in format 0,0,0"
			"and be between 0 and 255\n");
		return (0);
	}
	return (1);
}

int	validate_light(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 4)
	{
		printf("Error\nWrong number of arguments in light\n");
		return (clean_return(0, (void **)split));
	}
	if (!validate_light_values(split))
		return (clean_return(0, (void **)split));
	return (clean_return(1, (void **)split));
}
