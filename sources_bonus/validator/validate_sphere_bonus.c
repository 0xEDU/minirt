/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:44:32 by etachott          #+#    #+#             */
/*   Updated: 2023/04/25 21:12:57 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	int	validate_sphere_values(char **split)
{
	if (!validate_position(split[1]))
	{
		printf("Error\nSphere position must be in format 0,0,0\n");
		return (0);
	}
	if (!validate_float(split[2]))
	{
		printf("Error\nSphere diameter must be a float\n");
		return (0);
	}
	if (!validate_color(split[3]))
	{
		printf("Error\nSphere color must be in format 0,0,0"
			" and values must be between 0 and 255\n");
		return (0);
	}
	return (1);
}

int	validate_sphere(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 4)
	{
		printf("Error\nWrong number of arguments in sphere\n");
		return (clean_return(0, (void **)split));
	}
	if (!validate_sphere_values(split))
		return (clean_return(0, (void **)split));
	return (clean_return(1, (void **)split));
}
