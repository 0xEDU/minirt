/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:25:43 by etachott          #+#    #+#             */
/*   Updated: 2023/04/19 21:40:25 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_double(char *line)
{
	int j;
	int i;

	j = 0;
	i = 0;
	// printf("double: %f\n", ft_atof(line));
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

static int	validate_vector(char **vector)
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
			printf("%c\n", vector[i][j]);
			if (!ft_isdigit(vector[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	printf("Não é pra chegar aqui\n");
	i = -1;
	// printf("Não era pra estar aqui\n");
	while (vector[++i])
	{
		if (!validate_double(vector[i]))
			return (0);
	}
	return (1);
}

static int	validate_position(char *position)
{
	int 	i;
	int		comma;
	char	**split;

	i = 0;
	comma = 0;
	while (position[i])
	{
		if (position[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (0);
	split = ft_split(position, ',');
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
	{
		ft_free_matrix((void **)split);
		return (0);
	}
	if (!validate_vector(split))
	{
		ft_free_matrix((void **)split);
		return (0);
	}
	ft_free_matrix((void **)split);
	return (1);
}

int	validate_camera(char *line)
{
	int		i;
	char	**split;

	i = 0;
	// printf("Entrou na validate_camera\n");
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 4)
		return (0);
	if (!validate_position(split[1]))
		return (0);
	// if (!validate_normal(split[2]))
	// 	return (0);
	// if (!validate_fov(split[3]))
	// 	return (0);
	ft_free_matrix((void **)split);
	return (1);
}