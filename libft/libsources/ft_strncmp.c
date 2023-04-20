/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:32:46 by coder             #+#    #+#             */
/*   Updated: 2023/04/19 20:02:19 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	Compare at most n bytes of string s1 and string s2.
*
*	@param const char	*s1: The first string to be compared;
*	@param const char	*s2: The second string to be compared;
*	@param size_t	n: The maximum number of bytes to be compared.
*
*	@return An integer less than, equal to, or greater than zero if s1 is
*	found, respectively, to be less than, to match, or be greater than s2.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	index;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	index = 0;
	if (n == 0)
		return (0);
	while ((s1[index] == s2[index]) && index < (n - 1))
	{
		if (s1[index] == '\0')
			break ;
		index++;
	}
	return (((unsigned char) s1[index]) - ((unsigned char) s2[index]));
}
