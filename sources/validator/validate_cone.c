/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:08:12 by etachott          #+#    #+#             */
/*   Updated: 2023/04/26 17:15:50 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_cone_first(char **split)
{
	if (!validate_position(split[1]))
	{
		printf("Error\nCone position must be in format 0,0,0\n");
		return (0);
	}
	if (!validate_normal(split[2]))
	{
		printf("Error\nCone normal must be in format 0,0,0"
			" and values must be between 1 and 0\n");
		return (0);
	}
	return (1);
}

static int	validate_cone_second(char **split)
{
	if (!validate_float(split[3]))
	{
		printf("Error\nCone height must be a float\n");
		return (0);
	}
	if (!validate_float(split[4]))
	{
		printf("Error\nCone angle must be a float\n");
		return (0);
	}
	if (!validate_color(split[5]))
	{
		printf("Error\nCone color must be in format 0,0,0"
			" and values must be between 0 and 255\n");
		return (0);
	}
	return (1);
}

int	validate_cone(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 6)
	{
		printf("Error\nWrong number of arguments in cone\n");
		return (clean_return(0, (void **)split));
	}
	if (!validate_cone_first(split))
		return (clean_return(0, (void **)split));
	if (!validate_cone_second(split))
		return (clean_return(0, (void **)split));
	return (clean_return(1, (void **)split));
}
