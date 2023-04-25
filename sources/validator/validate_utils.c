/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:17:07 by etachott          #+#    #+#             */
/*   Updated: 2023/04/24 21:21:34 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_normal(char *normal)
{
	// Refatorar
	int		i;
	int		comma;

	i = -1;
	comma = 0;
	while (normal[++i])
		if (normal[i] == ',')
			comma++;
	if (comma != 2)
		return (0);
	if (ft_strcmp(normal, "1,0,0") == 0)
		return (1);
	else if (ft_strcmp(normal, "-1,0,0") == 0)
		return (1);
	else if (ft_strcmp(normal, "0,1,0") == 0)
		return (1);
	else if (ft_strcmp(normal, "0,-1,0") == 0)
		return (1);
	else if (ft_strcmp(normal, "0,0,-1") == 0)
		return (1);
	else if (ft_strcmp(normal, "0,0,1") == 0)
		return (1);
	return (0);
}

int	validate_double(char *line)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (line[i] == '-')
		(i)++;
	while (ft_isdigit(line[i]))
	{
		(i)++;
		j++;
	}
	if (line[i] == '.')
	{
		(i)++;
		while (ft_isdigit(line[i]))
		{
			(i)++;
			j++;
		}
	}
	if (j == 0)
		return (0);
	return (1);
}

int	validate_vector(char **vector)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (vector[i][j])
		{
			if (!ft_isdigit(vector[i][j])
					&& vector[i][j] != '.' && vector[i][0] != '-')
				return (0);
			j++;
		}
		i++;
	}
	i = -1;
	while (vector[++i])
		if (!validate_double(vector[i]))
			return (0);
	return (1);
}

static	int	comma_check(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (0);
	return (1);
}

int	validate_position(char *position)
{
	int		i;
	char	**split;

	i = 0;
	if (!comma_check(position))
		return (0);
	split = ft_split(position, ',');
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		return (clean_return(0, (void **)split));
	if (!validate_vector(split))
		return (clean_return(0, (void **)split));
	return (clean_return(1, (void **)split));
}
