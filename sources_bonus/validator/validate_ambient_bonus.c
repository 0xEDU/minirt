/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:14 by etachott          #+#    #+#             */
/*   Updated: 2023/04/25 16:27:04 by etachott         ###   ########.fr       */
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
	{
		printf("Error\nWrong number of arguments in ambient\n");
		return (clean_return(0, (void **)split));
	}	
	if (!validate_ratio(split[1]))
	{
		printf("Error\nAmbient light ratio must be between 0 and 1\n");
		return (clean_return(0, (void **)split));
	}
	if (!validate_color(split[2]))
	{
		printf("Error\nAmbient light color must"
			"be in format 0,0,0 and be between 0 and 255\n");
		return (clean_return(0, (void **)split));
	}
	return (clean_return(1, (void **)split));
}
