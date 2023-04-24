/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:39:52 by etachott          #+#    #+#             */
/*   Updated: 2023/04/24 10:01:09 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hittable_list	*create_world(char *file, t_minirt *minirt)
{
	t_hittable_list	*world;
	int				i;
	int				fd;
	char			*line;

	i = 0;
	world = ft_calloc(sizeof(t_hittable_list), 1);
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == 'A')
			parse_ambient(line, &minirt->ambient);
		else if (line[0] == 'C')
			parse_camera(line, &minirt->camera);
		else if (line[0] == 'L')
			parse_light(line, &minirt->light);
		else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
			parse_sphere(line, world, minirt, &i);
		else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
			parse_plane(line, world, minirt, &i);
		else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
			parse_cylinder(line, world, minirt, &i);
		free(line);
	}
	close(fd);
	return (world);
}
