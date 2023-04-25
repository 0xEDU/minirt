/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:25:43 by etachott          #+#    #+#             */
/*   Updated: 2023/04/24 20:34:28 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_fov(char *fov)
{
	int	i;

	i = 0;
	while (fov[i] && fov[i] != '\n')
	{
		if (!ft_isdigit(fov[i]))
			return (0);
		i++;
	}
	if (ft_atoi(fov) < 0 || ft_atoi(fov) > 180)
		return (0);
	return (1);
}

int	validate_camera(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 4)
		return (clean_return(0, (void **)split));
	if (!validate_position(split[1]))
		return (clean_return(0, (void **)split));
	if (!validate_normal(split[2]))
		return (clean_return(0, (void **)split));
	if (!validate_fov(split[3]))
		return (clean_return(0, (void **)split));
	return (clean_return(1, (void **)split));
}