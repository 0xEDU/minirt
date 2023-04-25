/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:25:49 by etachott          #+#    #+#             */
/*   Updated: 2023/04/25 16:44:48 by etachott         ###   ########.fr       */
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

int	validate_color(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ',');
	while (split[i])
		i++;
	if (i != 3)
		return (clean_return(0, (void **)split));
	i = 0;
	while (split[i])
	{
		if (!validate_int(split[i]))
			return (clean_return(0, (void **)split));
		i++;
	}
	return (clean_return(1, (void **)split));
}

int	clean_return(int status_code, void **split)
{
	ft_free_matrix((void **)split);
	return (status_code);
}

int	validate_ratio(char *line)
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
	if ((0 < nb || nb > 1) && nb > 1)
		return (0);
	return (1);
}

int	validate_float(char *line)
{
	int		i;
	double	nb;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != '.')
			return (0);
		i++;
	}
	nb = ft_atof(line);
	if (nb < 0)
		return (0);
	return (1);
}
