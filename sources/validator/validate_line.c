/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:18:13 by etachott          #+#    #+#             */
/*   Updated: 2023/04/28 00:40:47 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_line(char *line, int iteration)
{
	if (line[1] != ' ' && iteration == 0)
	{
		printf("Error\nWrong spacing\n");
		return (0);
	}
	if (line[0] == 'C' && line[1] == ' ')
		return (validate_camera(line));
	if (line[0] == 'A' && line[1] == ' ')
		return (validate_ambient(line));
	if (line[0] == 'L' && line[1] == ' ')
		return (validate_light(line));
	if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		return (validate_sphere(line));
	if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		return (validate_plane(line));
	if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		return (validate_cylinder(line));
	if (line[0] == 'c' && line[1] == 'n' && line[2] == ' ')
		return (validate_cone(line));
	return (1);
}
