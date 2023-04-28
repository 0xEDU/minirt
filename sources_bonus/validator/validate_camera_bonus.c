/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:25:43 by etachott          #+#    #+#             */
/*   Updated: 2023/04/28 00:23:08 by guribeir         ###   ########.fr       */
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

static int	validate_camera_values(char **split)
{
	if (!validate_position(split[1]))
	{
		printf("Error\nCamera position must be in format 0,0,0\n");
		return (0);
	}
	if (!validate_normal(split[2]))
	{
		printf("Error\nCamera normal must be in format 0,0,0"
			" and values must be between 1 and 0\n");
		return (0);
	}
	if (!validate_fov(split[3]))
	{
		printf("Error\nCamera fov must be between 0 and 180\n");
		return (0);
	}
	return (1);
}

int	validate_camera(char *line)
{
	int		i;
	char	**split;
	int		len_line;
	int		len_split;

	i = 0;
	len_line = ft_strlen(line);
	split = ft_split(line, ' ');
	if (!split)
		return (0);
	len_split = ft_strlen(split[0]);
	if (len_split == len_line)
		return (clean_return(0, (void **)split));
	while (split[i])
		i++;
	if (i != 4)
	{
		printf("Error\nWrong number of arguments in camera\n");
		return (clean_return(0, (void **)split));
	}
	if (!validate_camera_values(split))
		return (clean_return(0, (void **)split));
	return (clean_return(1, (void **)split));
}
