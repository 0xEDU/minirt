/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:07:48 by etachott          #+#    #+#             */
/*   Updated: 2023/04/25 16:29:30 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_cylinder_first(char **split)
{
	if (!validate_position(split[1]))
	{
		printf("Error\nCylinder position must be in format 0,0,0\n");
		return (0);
	}
	if (!validate_normal(split[2]))
	{
		printf("Error\nCylinder normal must be in format 0,0,0"
			"and values must be between 1 and 0\n");
		return (0);
	}
	return (1);
}

static int	validate_cylinder_second(char **split)
{
	if (!validate_float(split[3]))
	{
		printf("Error\nCylinder diameter must be a float\n");
		return (0);
	}
	if (!validate_float(split[4]))
	{
		printf("Error\nCylinder height must be a float\n");
		return (0);
	}
	if (!validate_color(split[5]))
	{
		printf("Error\nCylinder color must be in format 0,0,0"
			"and values must be between 0 and 255\n");
		return (0);
	}
	return (1);
}

int	validate_cylinder(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 6)
	{
		printf("Error\nWrong number of arguments in cylinder\n");
		return (clean_return(0, (void **)split));
	}
	if (!validate_cylinder_first(split))
		return (clean_return(0, (void **)split));
	if (!validate_cylinder_second(split))
		return (clean_return(0, (void **)split));
	return (clean_return(1, (void **)split));
}
