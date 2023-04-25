/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:11:38 by etachott          #+#    #+#             */
/*   Updated: 2023/04/25 16:30:00 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_minimal_file(char *file)
{
	int		fd;
	int		counter;
	char	*line;

	counter = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == 'C' || line[0] == 'A' || line[0] == 'L')
			counter++;
		free(line);
	}
	close(fd);
	if (counter < 3)
	{
		printf("Error\nMissing Ambient, Camera or Light\n");
		return (0);
	}
	return (1);
}

int	validate_file(char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	if (!validate_minimal_file(file))
		return (0);
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!validate_line(line))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}
