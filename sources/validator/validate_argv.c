/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:05:38 by etachott          #+#    #+#             */
/*   Updated: 2023/04/25 16:12:04 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_argv(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		return (0);
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".rt", 4))
	{
		printf("Error\nWrong file extension\n");
		return (0);
	}
	return (1);
}
