/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:17:07 by etachott          #+#    #+#             */
/*   Updated: 2023/04/25 16:19:19 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	validate_normal(char *normal)
{
	int		i;
	char	**split;

	i = -1;
	if (!comma_check(normal))
		return (0);
	while (normal[++i])
	{
		if (!ft_isdigit(normal[i]) && normal[i] != '.'
			&& normal[i] != ',' && normal[i] != '-')
			return (0);
	}
	split = ft_split(normal, ',');
	i = -1;
	while (split[++i])
	{
		if (ft_atof(split[i]) != 0.0 && ft_atof(split[i]) != 1.0)
			return (clean_return(0, (void **)split));
	}
	return (clean_return(1, (void **)split));
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
