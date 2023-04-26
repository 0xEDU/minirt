/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:44:35 by coder             #+#    #+#             */
/*   Updated: 2023/04/25 21:30:24 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_buffer(int fd, char *buffer);
static char	*get_line(char *buffer);
static char	*go_to_next_line(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	if (buf == NULL)
		buf = set_buffer(fd, buf);
	if (buf == NULL)
		return (NULL);

	line = get_line(buf);
	if (line)
		buf = go_to_next_line(buf);
	else
	{
		free(buf);
		buf = NULL;
	}
	return (line);
}

static char	*set_buffer(int fd, char *buffer)
{
	char	*tmp;
	ssize_t	i;

	i = 0;
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (gnl_strchr(buffer, '\n') != 1)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == 0 || i == -1)
			break ;
		tmp[i] = '\0';
		buffer = gnl_strjoin(buffer, tmp);
		if (buffer == NULL)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	if (i == -1)
		return (NULL);
	return (buffer);
}

static char	*get_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	while (*(buffer + i) != '\0' && *(buffer + i) != '\n')
		i++;

	line = ft_calloc(i + (*(buffer + i) == '\n') + 1, sizeof(char));
	if (line == NULL)
		return (NULL);

	i = 0;
	while (*(buffer + i) != '\0' && *(buffer + i) != '\n')
	{
		*(line + i) = *(buffer + i);
		i++;
	}
	if (*(buffer + i) == '\n')
	{
		*(line + i) = '\n';
		i++;
	}
	return (line);
}

static char	*go_to_next_line(char *buffer)
{
	char	*next;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(buffer + i) != '\n' && *(buffer + i) != '\0')
		i++;
	if (*(buffer + i) == '\0')
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (next == NULL)
		return (NULL);
	i++;
	while (*(buffer + i + j) != '\0')
	{
		*(next + j) = *(buffer + i + j);
		j++;
	}
	free(buffer);
	return (next);
}
