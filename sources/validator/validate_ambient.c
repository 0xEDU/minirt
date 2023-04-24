/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:14 by etachott          #+#    #+#             */
/*   Updated: 2023/04/24 20:10:37 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_int(char *nb)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (nb[i] && nb[i] != '\n')
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	num = ft_atoi(nb);
	if (num < 0 || num > 255)
		return (0);
	return (1);
}

static int	validate_color(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ',');
	while (split[i])
		i++;
	if (i != 3)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!validate_int(split[i]))
			return (0);
		i++;
	}
	ft_free_matrix((void **)split);
	return (1);
}

static int	validate_ratio(char *line)
{
	int		i;
	double	nb;

	i = 0;
	nb = ft_atof(line);
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != '.')
			return (0);
		i++;
	}
	if ((0 < nb || nb > 1) && nb > 1) //essa condição não faz sentido
		return (0);
	return (1);
}

int	validate_ambient(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 3)
		return (0);
	if (!validate_ratio(split[1]))
		return (0);
	if (!validate_color(split[2]))
		return (0);
	ft_free_matrix((void **)split);
	return (1);
}