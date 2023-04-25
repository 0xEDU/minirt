/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:55:26 by etachott          #+#    #+#             */
/*   Updated: 2023/04/25 16:42:06 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	int	validate_plane_values(char **split)
{
	if (!validate_position(split[1]))
	{
		printf("Error\nPlane position must be in format 0,0,0\n");
		return (0);
	}
	if (!validate_normal(split[2]))
	{
		printf("Error\nPlane normal must be in format 0,0,0"
			"and values must be between 1 and 0\n");
		return (0);
	}
	if (!validate_color(split[3]))
	{
		printf("Error\nPlane color must be in format 0,0,0"
			"and values must be between 0 and 255\n");
		return (0);
	}
	return (1);
}

int	validate_plane(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 4)
	{
		printf("Error\nWrong number of arguments in plane\n");
		return (clean_return(0, (void **)split));
	}
	if (!validate_plane_values(split))
		return (clean_return(0, (void **)split));
	return (clean_return(1, (void **)split));
}
