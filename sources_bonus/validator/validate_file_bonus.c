/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:11:38 by etachott          #+#    #+#             */
/*   Updated: 2023/04/28 00:42:00 by guribeir         ###   ########.fr       */
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
	if (counter != 3)
	{
		printf("Error\nMissing Ambient, Camera or Light\n");
		return (0);
	}
	return (1);
}

int	validate_file(char *file, int iteration)
{
	char	*line;
	int		fd;
	int		success;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nWrong file name\n");
		return (0);
	}
	if (!validate_minimal_file(file))
		return (0);
	fd = open(file, O_RDONLY);
	success = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!validate_line(line, ++iteration))
			success = 0;
		free(line);
	}
	return (success);
}
