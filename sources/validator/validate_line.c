/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:18:13 by etachott          #+#    #+#             */
/*   Updated: 2023/04/28 17:17:04 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	is_valid_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_line(char *line, int iteration)
{
	if (line[0] == 'C' && line[1] == ' ')
		return (validate_camera(line));
	else if (line[0] == 'A' && line[1] == ' ')
		return (validate_ambient(line));
	else if (line[0] == 'L' && line[1] == ' ')
		return (validate_light(line));
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		return (validate_sphere(line));
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		return (validate_plane(line));
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		return (validate_cylinder(line));
	else if (!is_valid_empty_line(line))
	{
		if (iteration++)
			printf("Error\nWrong line\n");
		return (0);
	}
	return (1);
}
