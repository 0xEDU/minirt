/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:45:27 by coder             #+#    #+#             */
/*   Updated: 2023/04/25 20:59:23 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*k;

	k = malloc(ft_strlen(s1) + 1);
	if (k)
		ft_strlcpy(k, s1, (ft_strlen(s1) + 1));
	return (k);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;

	i = 0;
	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (dstsize < l_dst)
		return (l_src + dstsize);
	while (*(src + i) && i < (dstsize - l_dst - 1))
	{
		*(dst + l_dst + i) = *(src + i);
		i++;
	}
	*(dst + l_dst + i) = '\0';
	return (l_dst + l_src);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	nonull;
	size_t	ret;

	nonull = size - 1;
	ret = ft_strlen(src);
	if (size)
	{
		while (nonull-- && *src)
		{
			*dst = (char) *src;
			dst++;
			src++;
		}
		*dst = '\0';
	}
	return (ret);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(size * sizeof(char));
	if (new == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcat(new, s2, size);
	free(s1);
	return (new);
}
